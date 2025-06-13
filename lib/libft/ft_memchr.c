/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:39:14 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 11:24:04 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n > 0)
	{
		if ((unsigned char)*s2 == (unsigned char)c)
			return ((void *)s2);
		s2++;
		n--;
	}
	return (NULL);
}

// int	main()
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};

// 	printf("%s", (char *)ft_memchr(s, 2+ 256, 3));
// 	//printf("%s", s + 2);
// 	return (0);
// }
