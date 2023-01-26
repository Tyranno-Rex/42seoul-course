#include "minitalk.h"
#include "./ft_printf/ft_printf.h"
#include "libft/libft.h"

void send_msg(pid_t sv_pid, char *msg)
{
    unsigned char   c;
    int             nbr_bits;
    int             i = 0;

    while (msg[i])
    {
        // 메세지의 처음 캐릭터를 전달함
        c = msg[i++];
        nbr_bits = 0;
        // 8자리를 진행하면 됨
        while (nbr_bits++ < 8)
        {
            // and 연산 후 현재 명령어 보내기
            if (c & 0b1000000)
                kill(sv_pid, SIGUSR1);
            // 아니라면 현재 명령어 보내기
            else
                kill(sv_pid, SIGUSR2);
            sleep(1);
            c <<= 1;
        }
    }
}

void    ft_sigusr_handler(int sig_num)
{
    // 제대로 된 문자열이 들어오면 확인
    if (sig_num == SIGUSR2)
        ft_printf("");
    // 제대로된 문자열이 들어오지 않음
    else
        ft_printf("");
}

void	ft_check_signal(void)
{
    // sigaction의 구조체 값 받아온뒤 할당
	struct sigaction	sa_newsig;

	// 받아온는 2개의 인자에 대한 정보 처리를 진행할 함수를 설정
    sa_newsig.sa_sigaction = &ft_sigusr_handler;
	// 신호의 옵션에 SA_SIGINFO 옵션을 주어서 신호 처리부에서 2개의 인자를 처리하도록 진행함
	sa_newsig.sa_flags = SA_SIGINFO;

	// 시그널, 구조체, 그리고 널 값을 가지고 이에 대한 시그널 값을 가져온다.
    // 만약 실패한다면 에러 메세지를 띄운다.
    if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
        ft_printf("you can't handle SIGUSR1 command");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
        ft_printf("you can't handle SIGUSR1 command");
}

int main(int ac, char **av)
{
    // pid_t 로 교체하기
    unsigned int    sv_pid;
    int             i;
    
    i = 0;
    // 3가지의 인수가 들어와야함 (프로그램명/서버/메세지)
    if (ac != 3)
        ft_printf("you input wrong number");
    // 서버가 숫자로 입려괴었는지 학인하기
    while (av[1][i])
    {
        if (!ft_isdigit(av[1][i++]))
            ft_printf("PID is wrong input");
    }
    // 메세지가 제대로 들어왔는지 확인
    if (*av[2] == 0)
        ft_printf("you didn't send message");
    // 들어온 sv_pid를 숫자로 치환하기
    sv_pid = ft_atoi(av[1]);
    ft_check_signal();
    send_msg(sv_pid, av[2]);
    while (1)
        pause();
    return (1);
}