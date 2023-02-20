#include "push_swap.h"

bool is_valid_number(const char* str) {
    if (str[0] == '\0') 
        return false;
    if (str[0] == '-' || str[0] == '+') 
    {
        if (str[1] == '\0')
            return false;
        str++;
    }
    while (*str != '\0') 
    {
        if (!isdigit(*str))
            return false;
        str++;
    }
    return true;
}

bool has_duplicates(int argc, char** argv) {
    int i;
    int j;
    
    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc) 
        {
            if (strcmp(argv[i], argv[j]) == 0)
                return true;
            j++;
        }
        i++;
    }
    return false;
}

bool is_valid_input(int argc, char** argv) 
{
    int i;
    bool has_sign;
    
    i = 1;
    has_sign = false;
    while (i < argc)
    {
        if (!is_valid_number(argv[i])) 
            ft_show_error("Error: %s is not a valid number\n", argv[i]);
        int num = atoi(argv[i]);
        if (num == 0 && strcmp(argv[i], "0") != 0) 
            ft_show_error("Error: %s is not a valid number\n", argv[i]);
        if (has_sign && (num < 0 || argv[i][0] == '+')) 
            ft_show_error("Error: Only one sign is allowed\n");
        has_sign = has_sign || argv[i][0] == '-' || argv[i][0] == '+';
        i++;
    }
    if (has_duplicates(argc, argv)) 
        ft_show_error("Error: Duplicate values are not allowed\n");
    return true;
}

int	ft_check_ac_av(int ac, char **av)
{
    if (ac < 2) 
        ft_show_error("Error: argc must be at least 2\n");
    if (!is_valid_input(ac, av))
        return 1;
    ft_show_error("Input is valid\n");
    return 0;
}