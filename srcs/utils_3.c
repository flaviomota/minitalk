#include "minitalk.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_putstr_fd(char const *str, int fd)
{
	if (str != NULL)
		while (*str)
			ft_putchar_fd(*(str++), fd);
}