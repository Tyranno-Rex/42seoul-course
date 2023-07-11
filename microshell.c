#include "microshell.h"

int err(char *str) 
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n");
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    return 0;
}

int exec(char **argv, char **envp, int i) 
{
    // 이 함수는 새로운 프로세스를 생성하고 argv[i]에 지정된 명령을 실행합니다.
    // fd[2]는 두 개의 파일 디스크립터의 배열입니다.
    // status는 자식 프로세스의 종료 상태입니다.
    // has_pipe는 명령에 파이프가 있는지 여부를 나타내는 불리언 변수입니다.
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    // 파이프가 있는 경우 파이프를 생성합니다.
    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");
    // 새로운 자식 프로세스를 생성합니다.
    int pid = fork();
    if (!pid) 
    {
        // argv[i]를 0으로 설정하여 자식 프로세스가 파이프 문자를 실행하지 않도록 합니다.
        argv[i] = 0;
        // 파이프가 있는 경우 자식 프로세스의 stdout을 파이프의 쓰기 끝으로 리디렉션합니다.
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        // argv[i]에 지정된 명령을 실행합니다.
        execve(*argv, argv, envp);
        // execve() 호출이 실패하면 오류 메시지를 출력합니다.
        return err("error: cannot execute "), err(*argv), err("\n");
    }
    // 자식 프로세스가 종료될 때까지 기다립니다.
    waitpid(pid, &status, 0);
    // 파이프가 있는 경우 부모 프로세스의 stdin을 파이프의 읽기 끝으로 리디렉션합니다.
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    // 자식 프로세스의 종료 상태를 반환합니다.
    return WIFEXITED(status) && WEXITSTATUS(status);
}


int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i);
            else if (i)
                status = exec(argv, envp, i);
        }
    }
    return status;
}