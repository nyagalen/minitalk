/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:08:43 by svydrina          #+#    #+#             */
/*   Updated: 2023/05/13 18:59:58 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (i > 0 && s[i - 1] == c && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	**malloc_arr(char **arr, char const *str, char c)
{
	int	str_i;
	int	arr_i;
	int	len;

	str_i = 0;
	arr_i = 0;
	while (str[str_i])
	{
		len = 0;
		while (str[str_i] && str[str_i] == c)
			str_i++;
		if (str[str_i] && str[str_i] != c)
		{
			while (str[str_i] && str[str_i] != c)
			{
				len++;
				str_i++;
			}
			arr[arr_i] = malloc(len + 1);
			ft_memcpy(arr[arr_i], str + str_i - len, len);
			arr[arr_i++][len] = '\0';
		}
	}
	arr[arr_i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**new_arr;
	int		word_count;

	word_count = word_cnt(s, c);
	new_arr = malloc((word_count + 1) * sizeof(char **));
	if (!new_arr)
		return (NULL);
	new_arr = malloc_arr(new_arr, s, c);
	return (new_arr);
}
