#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int err(char *msg)
{
    i = 0;
    while (msg[i])
        write(2, msg[i++], 1);
    return 1;
}

int cd(char **argv, int i)
{
    if (i != 2)
        return err("error msg\n");
    else if (chdir(argv[1]) == -1)
        return err("error msg\n");
    return (0);
}

int exec(char **argv, char **envp, int i)
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");
    if (has_pipe && pipe(fd) == -1)
        return err("error : fatal\n");
    
    
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;
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