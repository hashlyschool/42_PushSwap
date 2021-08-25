#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	else
		return (0);
}
