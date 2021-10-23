/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:09:52 by fmota             #+#    #+#             */
/*   Updated: 2021/09/25 20:09:56 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	character(unsigned char letter)
{
	write(1, &letter, 1);
	return (1);
}

int	number(int nb)
{
	int	index;

	if (nb < 0)
	{
		character('-');
		nb = nb * -1;
	}
	if (nb > 0)
	{
		index = nb % 10;
		nb = nb / 10;
		number(nb);
		character(48 + index);
	}
	return (1);
}

void	checker(int dot)
{
	static unsigned char	str = '\0';
	static int				nb = 0;
	int						index;

	index = 1;
	if (dot == SIGUSR1)
	{
		if (nb < 7)
			str = str << 1;
		nb++;
	}
	if (dot == SIGUSR2)
	{
		str = str | index;
		if (nb < 7)
			str = str << 1;
		nb++;
	}
	if (nb == 8)
	{
		character(str);
		nb = 0;
		str = '\0';
		index = 1;
	}
}

int	server(void)
{
	int	nb;

	nb = getpid();
	if (nb == -1)
		return (0);
	number(nb);
	character('\n');
	return (nb);
}

int	main(int argc, char **argv)
{
	int		index;
	char	*str;

	str = argv[2];
	ft_putstr("Server pid : ");
	index = server();
	while (1)
	{
		signal(SIGUSR1, checker);
		signal(SIGUSR2, checker);
	}
}
