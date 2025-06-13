/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:01:14 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 11:23:39 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*res;
	int				i;

	res = (unsigned char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (res[i] == (unsigned char) c)
		{
			return ((char *)&res[i]);
		}
		i--;
	}
	return (NULL);
}
