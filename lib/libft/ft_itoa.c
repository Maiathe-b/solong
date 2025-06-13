/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:41 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 14:52:52 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	else
	{
		if (n < 0)
			i++;
		while (n != 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_len(n);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else if (n == 0)
		str = ft_strdup("0");
	else
	{
		str = ft_calloc(len + 1, sizeof(char));
		if (!str)
			return (NULL);
		if (n < 0)
		{
			n = -n;
			str[0] = '-';
		}
		while (n != 0)
		{
			str[(--len)] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}
