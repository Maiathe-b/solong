/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:45:43 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/21 11:10:48 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(total_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1)) + 1);
	ft_strlcat(str, s2, (total_len + 1));
	return (str);
}

// int main()
// {
// 	char * s = ft_strjoin("tripouille", "42");
// 	printf("%s", s);
// }
