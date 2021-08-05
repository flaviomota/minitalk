#include "minitalk.h"

int	changeover(unsigned char str, int dest, int count)
{
	if (count < 8)
	{
		changeover(str >> 1, dest, count + 1);
		if ((str % 2) == 0)
			kill(dest, SIGUSR1);
		else
			kill(dest, SIGUSR2);
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	dest;
	int	num;
	int	index;

	index = 0;
	dest = acess_num(argv[1]);
	if (argc < 3)
		write(2, "usage: ./client [pid server] [message]\n", 39);
	if (argc == 3)
	{
		while (argv[2][index] != '\0')
		{
			changeover(argv[2][index], dest, 0);
			index++;
			write(2, "ok\n", 3);
		}
	}
}