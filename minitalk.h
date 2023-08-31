/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:47:02 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/28 21:00:46 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

extern int	g_received;
/*
typedef struct	string
{
	char	*str;
	int		len;
}	t_string;
*/

int	listener(int sig, void (*sigact) (int, siginfo_t*, void*), int options);

#endif
