#include "minitalk.h"

int	ft_putchar(unsigned char u_c)
{
	write(1, &u_c, 1);
	return (1);
}

int	ft_putnb(int nb)
{
	int	initial;
	int	final;

	initial = 0;
	final = max_checker(nb);
	if (final == 0)
	{
		nb = neg_checker(nb);
		initial = counter(nb);
		while (initial >= 1)
		{
			if (nb / initial > 0)
			{
				ft_putchar(48 + nb / initial);
				nb = nb % initial;
			}
			else
				ft_putchar(48);
			initial = initial / 10;
		}
	}
	return (0);
}

int	max_checker(int nb)
{
	int	max;

	max = 0;
	if (nb == -2147483648)
	{
		max = 1;
		ft_putchar(45);
		ft_putchar(50);
		ft_putchar(49);
		ft_putchar(52);
		ft_putchar(55);
		ft_putchar(52);
		ft_putchar(56);
		ft_putchar(51);
		ft_putchar(54);
		ft_putchar(52);
		ft_putchar(56);
	}
	return (max);
}

int	neg_checker(int nb)
{
	if (nb < 0)
	{
		ft_putchar(45);
		nb = nb * -1;
	}
	return (nb);
}

int	counter(int nb)
{
	int	ascii;
	int	initial;

	initial = 1;
	ascii = 0;
	while (ascii == 0)
	{
		if (nb / initial < 10)
			ascii = 1;
		else
			initial = initial * 10;
	}
	return (initial);
}