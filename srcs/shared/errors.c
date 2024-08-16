#include "shared.h"

void	ft_print_error(char *error_msg)
{
	ft_dprintf(2, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}