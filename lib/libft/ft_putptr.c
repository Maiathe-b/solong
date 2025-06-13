/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:54:55 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/02 12:12:13 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr(size_t n)
{
	int			i;
	const char	*hex = "0123456789abcdef";

	i = 0;
	if (n > 15)
	{
		i += ft_putptr(n / 16);
	}
	i += ft_putchar_fd(hex[n % 16], 1);
	return (i);
}

int	ft_validcheck(size_t n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (ft_putstr_fd("0x", 1) + ft_putptr(n));
}
