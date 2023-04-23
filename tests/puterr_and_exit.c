#include "minirt.h"

void	puterr_and_exit(char *err, char *target)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(target, 2);
	exit(1);
}
