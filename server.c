/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:43:00 by eunjeong          #+#    #+#             */
/*   Updated: 2023/01/26 15:43:03 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

void	ft_sigusr_handler(int signum, siginfo_t *info, void *ucontent)
{
    // 값이 함수를 진행해도 변하지 않아야 하기 때문에 static 값으로 두었다.
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_printf("%c", c);
		c = 0;
        // siginfo_t 구조체의 si_pid값과 시그널 값을 프로세스에 전달한다. 만약 전달되지 못한다면 -1을 반환한다.
        if (kill(info->si_pid, SIGUSR2) == -1)
            ft_printf("Server can't send SIGUSR2");
		return ; // 프로세스 중지
	}
    // 
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf("Server fail to send SIGUSR1");
}

void	ft_check_sig(void)
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

int	main(void)
{
    // pid의 자료형인  pid_t자료형의 값을 사용함
	pid_t	pid;

    // pid 값 구하기
	pid = getpid();
    // pid값 확인
    ft_printf("PID : %d\n", pid);
	while (1)
		ft_check_sig();
	return (0);
}
