#include "../includes/minitalk.h"

// 시그널을 받았을시에 비트 처리하는 함수
void	get_sig(int sig)
{
	// 비트를 저장하는 정적 변수
	static char	temp;
	// 비트를 얼마나 받았는지 확인하는 정적 변수
	static int	bit;
	
	ft_printf("bit : %d\n", bit);
	if (sig == SIGUSR1)
	{
 		// temp와 0을 or연산하여 그 값을 temp에 입력
		temp |= 0;
		// 비트가 8이 아닐경우 좌측으로 1만큼 shift
		if (bit < 7)
			temp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		// temp와 1을 or연산하여 그 값을 temp에 입력
		temp |= 1;
		// 비트가 8이 아닐경우 좌측으로 1만큼 shift
		if (bit < 7)
			temp <<= 1;
	}
	bit++;
	// 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	if (bit == 8)
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	// pid의 자료형인  pid_t자료형의 값을 사용함
	pid_t	pid;

    // pid 값 구하기
	pid = getpid();
	// 서버 실행시 pid 출력하는 로직
	ft_printf("SERVER PID = %d\n\n", pid);
	// 사용자 지정 시그널을 받으면 처리할 함수 지정해주기
	signal(SIGUSR1, get_sig);
	ft_printf("hello\n");
	signal(SIGUSR2, get_sig);
	// 요청이 들어올때까지 계속 대기하기
	while (1)
		pause();
}