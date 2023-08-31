/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:41:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/25 02:57:48 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	long	l;
	int		res;

	l = n;
	res = 0;
	if (n < 0)
	{
		res += ft_putchar('-');
		l *= -1;
	}
	res += ft_put_posint((unsigned int)l);
	return (res);
}
