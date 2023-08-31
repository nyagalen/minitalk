/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:47 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/25 02:57:15 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long l)
{
	int	res;

	res = 0;
	if (l == 0)
		return (ft_putstr("(nil)"));
	res += ft_putstr("0x");
	res += ft_puthex(l, 'x');
	return (res);
}
