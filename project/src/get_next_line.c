#include "push_swap.h"

static char	*ft_get_surplus(char *surplus, char **buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	free(*buf);
	if (!surplus)
		return (NULL);
	while (surplus[i] && surplus[i] != '\n')
		i++;
	if (!surplus[i])
	{
		free(surplus);
		return (NULL);
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
	int		len;

	i = 0;
	if (!surplus)
		return (NULL);
	while (surplus[i] && surplus[i] != '\n')
		i++;
	if (surplus[i] == '\n')
		i++;
	surplus_end = malloc(sizeof(char) * (i + 1));
	if (!surplus_end)
		return (NULL);
	len = i;
	i = 0;
	while (i < len)
	{
		surplus_end[i] = surplus[i];
		i++;
	}
	surplus_end[len] = '\0';
	return (surplus_end);
}

static char	*ft_malloc_check_error(int fd, ssize_t *nbr,
	char free_surplus, char **surplus)
{
	char	*buf;

	if (free_surplus)
	{
		free(*surplus);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*nbr = 1;
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

char	*get_next_line(int fd, char free_surplus)
{
	static char	*surplus;
	char		*buf;
	ssize_t		rtn_read;
	char		*str;

	buf = ft_malloc_check_error(fd, &rtn_read, free_surplus, &surplus);
	if (!buf)
		return (NULL);
	while (!(ft_sheck_rtn(surplus)) && rtn_read != 0)
	{
		rtn_read = ft_read_in_buf(fd, &buf);
		if (rtn_read == -1)
			return (NULL);
		surplus = ft_strjoin_free(surplus, buf);
		if (!surplus)
			return (NULL);
	}
	str = ft_get_str(surplus);
	surplus = ft_get_surplus(surplus, &buf);
	if (rtn_read == 0 && ft_strlen(str) == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
