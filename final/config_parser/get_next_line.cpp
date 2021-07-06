
#include "get_next_line.hpp"

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != '\0')
		l += 1;
	return (l);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i += 1;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*str_sum;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_sum = new char[s1_len + s2_len + 1];
	i = 0;
	while (i < s1_len)
	{
		str_sum[i] = s1[i];
		i += 1;
	}
	while (i < s1_len + s2_len)
	{
		str_sum[i] = s2[i - s1_len];
		i += 1;
	}
	str_sum[i] = '\0';
	return (str_sum);
}

static void	shift_left(char *buff, size_t length)
{
	size_t i;

	i = 0;
	while (length + i <= GNL_BUF_SIZE)
	{
		buff[i] = buff[length + i];
		i += 1;
	}
	while (i < GNL_BUF_SIZE)
		buff[i++] = '\0';
}

static size_t	get_return_pos(char *buff)
{
	size_t ret_pos;

	ret_pos = 0;
	while (buff[ret_pos] != '\0' && buff[ret_pos] != '\n')
		ret_pos += 1;
	return ret_pos;
}

int	fget_next_line(int fd, char *buff, char **line, char *temp_line)
{
	int read_res;
	int line_size;
	char* temp_line_local;
	char* temp_line_local_2;
	size_t ret_pos;

	line_size = 0;
	ret_pos = get_return_pos(buff);
	if (buff[ret_pos] == '\n')
	{
		size_t i;
		temp_line_local = new char[ret_pos + 1];
		i = ft_strlcpy(temp_line_local, buff, ret_pos + 1);
		if (temp_line)
		{
			*line = ft_strjoin(temp_line, temp_line_local);
			delete[] temp_line;
			//temp_line = NULL;
			delete[] temp_line_local;
		}
		else
			*line = temp_line_local;
		shift_left(buff, ret_pos + 1);
		return (1);
	}
	else if (ret_pos > 0 && buff[ret_pos - 1] != '\0')
	{
		temp_line_local = new char[ret_pos + 1];
		//temp_line_local = (char*)malloc(sizeof(char) * (ret_pos + 1));
		ft_strlcpy(temp_line_local, buff, ret_pos + 1);
		if (temp_line)
		{
			temp_line_local_2 = ft_strjoin(temp_line, temp_line_local);
			delete[] temp_line;
			temp_line = NULL;
			temp_line_local = NULL;
			delete[] temp_line_local;
			temp_line = temp_line_local_2;
		}
		else
			temp_line = temp_line_local;
		shift_left(buff, ret_pos);
	}
	read_res = read(fd, buff, GNL_BUF_SIZE);
	if (read_res == -1)
	{
		std::cout << "error while reading file: " << std::strerror(errno) << std::endl;
		exit(1);
	}
	else if (read_res == 0 && !temp_line)
		return 0;
	else if (read_res == 0 && temp_line)
	{
		*line = temp_line;
		return (1);
	}
	return fget_next_line(fd, buff, line, temp_line);
}
