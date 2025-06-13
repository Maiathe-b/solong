/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:29:02 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/02 12:22:02 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printvar(char const c, va_list ap, int *res)
{
	if (c == 'c')
		*res += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		*res += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		*res += ft_validcheck(va_arg(ap, size_t));
	else if (c == 'd' || c == 'i')
		*res += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		*res += ft_unsputnbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		*res += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		*res += ft_putchar_fd('%', 1);
	else
		*res = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(arg, format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_printvar(format[i + 1], arg, &res);
			i++;
		}
		else
			res += ft_putchar_fd(format[i], 1);
		if (res == -1)
			break ;
		i++;
	}
	va_end (arg);
	return (res);
}
