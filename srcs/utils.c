#include "minitalk.h"

int	negative(char *str)
{
	int	index;
	int	neg;

	index = 0;
	neg = 1;
	while (str[index] != '\0')
	{
		if (str[index] == '-')
			neg = neg * -1;
		else if (str[index] != '+' && str[index] != 32)
			return (neg);
		index = index + 1;
	}
	return (neg);
}

int	number_checker(char *str, int nb, int count, int nb_verify)
{
	if (str[count] < 48 || str[count] > 57)
	{
		if (str[count] == 32 && nb_verify == 0)
			return (0);
		else if ((str[count] < 48 || str[count] > 57) && str[count] != '+'
				&& str[count] != '-' || nb_verify == 1 && (str[count] == '+'
				|| str[count] == '-'))
			return (1);
	}
	else
	{
		if (nb == 214748364 && str[count] - 48 > (15 - negative(str)) / 2
			|| nb >= 214748365)
			return (1);
	}
	return (0);
}

int	acess_num(char *str)
{
	int	nb_verify;
	int index;
	int	nb;

	index = 0;
	nb = 0;
	nb_verify = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 48 && str[index] <= 57)
		{
			if (number_checker(str, nb, index, nb_verify) == 1)
				return (0);
			nb = nb * 10 + str[index] - 48;
			nb_verify = 1;
		}
		else if (number_checker(str, nb, index, nb_verify) == 1)
			return (nb * negative(str));
		index = index + 1;
	}
	return (nb + negative(str));
}