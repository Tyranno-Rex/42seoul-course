#include "../includes/minitalk.h"

void	send_sig(int pid, char *str, int length)
{
	// 문자열의 인덱스
	int	byte_index;
	// 문자의 인덱스
	int	bit_index;
	// 전송할 비트를 나누는 변수
	int	bit_temp;

	byte_index = 0;
	// 들어온 문자열의 길이만큼 루프를 돔
	while (byte_index < length)
	{
		bit_index = 0;
		// 문자열의 문자만큼 루프를 돔
		while (bit_index < 8)
		{
	/*
	str[byte_index] >> (7 - bit_index)만큼 shift 연산한다
	그 값을 1로 and연산해서 비트를 구한다.
	뒤 비트부터 보내야 서버에서 비트를 받아서 문자 출력이 가능함.
	*/
			bit_temp = str[byte_index] >> (7 - bit_index) & 1;
		// bit_temp가 0이면 사용자 지정 시그널 1을 보냄
			if (bit_temp == 0)
				kill(pid, SIGUSR1);
		// bit_temp가 0이면 사용자 지정 시그널 2를 보냄
			else if (bit_temp == 1)
				kill(pid, SIGUSR2);
		// 전송 후 다른 처리를 위해 30 마이크로초만큼 스레드 일시정지
			usleep(100);
			bit_index++;
		}
		// 문자 하나 전송 후 300 마이크로초만큼 스레드 일시정지
		usleep(1000);
		byte_index++;
	}
}

// 문자열의 길이를 확인하고 마지막부분에 \n을 추가하는 함수
void	get_str(int pid, char *str)
{
	// 문자열의 길이
	int		length;
	// \n까지 포함한 문자열
	char	*send;
	
	// 문자열 합침
	send = ft_strjoin(str, "\n");
	if (send == NULL)
		exit(1);
	// 문자열의 길이를 구함
	length = ft_strlen(send);
	// 시그널을 보냄
	send_sig(pid, send, length);
	// malloc으로 할당한 문자열 해제
	free(send);
	// 정상 종료
	exit(0);
}

// 전달값 : 서버의 PID and 서버로 전송할 문자열
int	main(int ac, char **av)
{
	pid_t	pid;
	int 	i;

	i = 0;
	// 매개변수 2개가 들어왔는지 확인    
	if (ac != 3)
	{
		ft_printf("Argument is Wrong!!\n");
		exit(1);
	}
	// argv는 문자열로 들어오기 때문에 정수로 변환
	pid = ft_atoi(av[1]);
	while (av[1][i])
    {
        if (!ft_isdigit(av[1][i++]))
            ft_printf("PID is wrong input");
    }
    // 메세지가 제대로 들어왔는지 확인
    if (av[2] == 0)
        ft_printf("you didn't send message");
	// pid와 argv[2]의 문자열을 보냄.
	get_str(pid, av[2]);
}