/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:05:20 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/02 19:47:37 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	c;
	size_t	i;
	int		tot;
	size_t	a;

	tot = ft_strlen(src) + ft_strlen(dst);
	i = (size_t)ft_strlen(dst);
	if ((size_t)(ft_strlen(dst)) >= size)
		return (size + ft_strlen(src));
	c = 0;
	a = ft_strlen(dst);
	while (src[c] != '\0' && (c + a) < (size - 1))
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return ((size_t)tot);
}
