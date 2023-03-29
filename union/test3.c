#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    static char str[256];
    if (argc == 3)
    {
        i = 1;
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                if (str[(int)argv[i][j]] == 0)
                {
                    write(1, &argv[i][j], 1);
                    str[(int)argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}