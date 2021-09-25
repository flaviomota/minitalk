/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:10:38 by fmota             #+#    #+#             */
/*   Updated: 2021/09/25 20:10:52 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
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
