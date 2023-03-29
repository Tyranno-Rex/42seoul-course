#include <unistd.h>


int main(int ac, char **av)
{
    int         i, j;
    static int  str[256];

    if (ac == 3)
    {
        i = 1;
        while (i <= 2)
        {
            j = 0;
            while (av[i][j])
            {
                if (str[(int)av[i][j]] == 0)
                {
                    write(1, &av[i][j], 1);
                    str[(int)av[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
        
    }
    write(1, "\n", 1);
    return (0);
}