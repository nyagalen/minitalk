/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:08:13 by svydrina          #+#    #+#             */
/*   Updated: 2023/08/25 02:54:35 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	options(va_list args, char c)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (c == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		res += ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		res += ft_put_posint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		res += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, s);
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != '%')
			res += ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			res += options(args, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
