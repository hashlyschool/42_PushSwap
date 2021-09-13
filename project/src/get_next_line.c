#include "push_swap.h"

static char	*ft_get_surplus(char *surplus)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!surplus)
		return (0);
	while (surplus[i] && surplus[i] != '\n')
		i++;
	if (!surplus[i])
	{
		free(surplus);
		return (0);
	}
	str = malloc(sizeof(char) * ((ft_strlen(surplus) - i) + 1));
	if (!str)
		return (0);
	i++;
	while (surplus[i])
		str[j++] = surplus[i++];
	str[j] = '\0';
	free(surplus);
	return (str);
}

static char	*ft_get_str(char *surplus)
{
	int		i;
	char	*surplus_end;

	i = 0;
	if (!surplus)
		return (0);
	while (surplus[i] && surplus[i] != '\n')
		i++;
	surplus_end = malloc(sizeof(char) * (i + 1));
	if (!surplus_end)
		return (0);
	i = 0;
	while (surplus[i] && surplus[i] != '\n')
	{
		surplus_end[i] = surplus[i];
		i++;
	}
	surplus_end[i] = '\0';
	return (surplus_end);
}

static char	*ft_malloc_check_error(int fd, char **str)
{
	char	*buf;

	if (fd < 0 || !str || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return (buf);
}

static ssize_t	ft_read_in_buf(int fd, char **buf)
{
	ssize_t	rtn_read;

	rtn_read = read(fd, *buf, BUFFER_SIZE);
	if (rtn_read == -1)
	{
		free(*buf);
		return (-1);
	}
	(*buf)[rtn_read] = '\0';
	return (rtn_read);
}

int	get_next_line(int fd, char **str)
{
	static char	*surplus;
	char		*buf;
	ssize_t		rtn_read;

	buf = ft_malloc_check_error(fd, str);
	if (!buf)
		return (-1);
	rtn_read = 1;
	while (!(ft_sheck_rtn(surplus)) && rtn_read != 0)
	{
		rtn_read = ft_read_in_buf(fd, &buf);
		if (rtn_read == -1)
			return (-1);
		surplus = ft_strjoin_free(surplus, buf);
		if (!surplus)
			return (-1);
	}
	*str = ft_get_str(surplus);
	surplus = ft_get_surplus(surplus);
	free(buf);
	return (!!rtn_read);
}
