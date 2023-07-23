/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:59:46 by svydrina          #+#    #+#             */
/*   Updated: 2023/07/21 18:28:28 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	send_bits(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		c = *str++;
		i = 8;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (!pid)
		return (1);
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_bits(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
