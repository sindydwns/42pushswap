#include <stdlib.h>
#include "libft.h"

void    errorhandling(char *msg)
{
    if (DEBUG_MODE == 1)
        ft_putstr_fd(msg, 2);
    else
        ft_putstr_fd("Error\n", 2);
    exit(1);
}