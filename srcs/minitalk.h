#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

//utils.c
int		negative(char *str);
int		number_checker(char *str, int nb, int count, int nb_verify);
int		acess_num(char *str);
//utils_2.c
int		ft_putchar(unsigned char u_c);
int		ft_putnb(int nb);
int		max_checker(int nb);
int		neg_checker(int nb);
int		counter(int nb);
//utils_3.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *str);
void	ft_putstr_fd(char const *str, int fd);
//main_client.c
int		changeover(unsigned char str, int dest, int count);
//main_server.c
int		character(unsigned char letter);
int		number(int nb);
void	checker(int dot);
int		server(void);

#endif