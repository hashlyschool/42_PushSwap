#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_malloc_strlen(char **surplus, char *buf,
		size_t *len_sur, size_t *len_buf)
{
	if (!(*surplus))
	{
		*surplus = malloc(1);
		(*surplus)[0] = 0;
	}
	if (!(*surplus) || !buf)
		return ;
	*len_sur = ft_strlen(*surplus);
	*len_buf = ft_strlen(buf);
	return ;
}

char	*ft_strjoin_free(char *surplus, char *buf)
{
	char	*ptr;
	size_t	len_sur;
	size_t	len_buf;

	ft_malloc_strlen(&surplus, buf, &len_sur, &len_buf);
	if (!surplus || !buf)
		return (NULL);
	ptr = (char *)malloc(sizeof(*surplus) * (len_sur + len_buf + 1));
	if (!ptr)
	{
		free (buf);
		return (NULL);
	}
	while (*surplus)
		*ptr++ = *surplus++;
	while (*buf)
		*ptr++ = *buf++;
	*ptr = 0;
	free(surplus - len_sur);
	return (ptr - len_sur - len_buf);
}

int	ft_sheck_rtn(char *surplus)
{
	int	i;

	i = 0;
	if (!surplus)
		return (0);
	while (surplus[i])
	{
		if (surplus[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
