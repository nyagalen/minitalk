/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetlana <svetlana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:43:34 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/31 15:15:15 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = -1;

int	receive(int count)
{
	int	r;

	r = 0;
	while (1)
	{
		while (g_received == -1)
			continue ;
		r += g_received;
		g_received = -1;
		if (--count == 0)
			return (r);
		else
			r <<= 1;
	}
}

void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_received = 1;
	else if (sig == SIGUSR2)
		g_received = 0;
	kill(info->si_pid, sig);
}

int	listener(int sig, void (*sigact) (int, siginfo_t*, void*), int options)
{
	struct sigaction	sa;
	int					r;

	sa.sa_sigaction = sigact;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = options;
	r = sigaction(sig, &sa, NULL);
	return (r);
}

void	get_str(void)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = receive(32);
	s = malloc(len + 1);
	if (!s)
	{
		ft_printf("Malloc error\n");
		exit(0);
	}
	while (i < len)
		s[i++] = (char)receive(8);
	s[i] = '\0';
	ft_printf("%s\n", s);
	free(s);
}

int	main(void)
{
	ft_printf("Pid: %u\n", getpid());
	listener(SIGUSR1, &action, SA_SIGINFO);
	listener(SIGUSR2, &action, SA_SIGINFO);
	while (1)
	{
		get_str();
	}
}
