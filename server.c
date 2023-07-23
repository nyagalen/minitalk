/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:53:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/07/21 18:28:03 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static pid_t	pid = 0;
	static char		c = 0;
	static int		i = 0;	

	(void)context;
	if (!pid)
		pid = info->si_pid;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		kill(pid, SIGUSR1);
		c = 0;
	}
	else
		c <<= 1;
}	

int	main(void)
{
	struct sigaction	sigact;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = action;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	while (1)
		pause();
	return (0);
}		
