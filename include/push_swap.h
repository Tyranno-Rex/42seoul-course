
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifdef _WIN32
	#include <io.h>
#else
	#include <unistd.h>
#endif


#include "../ft_printf/ft_printf.h"
#include "../lib/libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

typedef struct s_push_swap
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_push_swap	*next;
}	t_push_swap;

#endif
