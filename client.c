/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetlana <svetlana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:04:05 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/31 15:23:56 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = -1;

static void	action(int sig)
{
	static int	int_count = 32;
	static int	char_count = 8;
	static char	c = 0;

	if (sig == SIGUSR1)
		g_received = 1;
	else if (sig == SIGUSR2)
		g_received = 0;
	if (int_count > 0)
		int_count--;
	else
	{
		if (char_count--)
			c += g_received;
		if (char_count == 0)
		{
			ft_putchar_fd(c, 1);
			char_count = 8;
			c = 0;
		}
		else
			c <<= 1;
	}
}

static int	send_bit(int pid, int c_or_i, int i)
{
	int	sig;

	if (c_or_i >> i & 1)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	g_received = -1;
	if (kill(pid, sig))
		return (-1);
	sig = -1;
	while (g_received == -1 && ++sig <= 200)
		usleep(1);
	return (g_received);
}

static void	send_len(int pid, int len)
{
	int	i;

	i = 32;
	while (i--)
	{
		if (send_bit(pid, len, i) < 0)
		{
			ft_printf("Error");
			exit(0);
		}
		usleep(50);
	}
}

static void	send_bits(int pid, char *str)
{
	int		i;
	char	c;

	send_len(pid, ft_strlen(str));
	while (*str)
	{
		c = *str++;
		i = 8;
		while (i--)
		{
			if (send_bit(pid, c, i) < 0)
			{
				ft_printf("Error");
				exit(0);
			}
			usleep(50);
		}
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments, try again");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("Wrong PID");
		return (1);
	}
	ft_printf("client's pid: %u\n", getpid());
	ft_printf("Sending %d symbols\n", ft_strlen(argv[2]));
	ft_printf("Server received message: ");
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_bits(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
