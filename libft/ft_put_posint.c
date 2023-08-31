/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_posint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:27:00 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/25 02:55:50 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_posint(unsigned int u)
{
	if (u < 10)
		return (ft_putchar(u + 48));
	return (ft_put_posint(u / 10) + ft_put_posint(u % 10));
}
