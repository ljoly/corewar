/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:02:09 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:02:10 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		c;

	i = -1;
	c = 0;
	while (src[c] != '\0')
		c++;
	if (len <= c)
	{
		while (++i < len)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	else
	{
		while (++i < c)
			dst[i] = src[i];
		while (i < len)
			dst[i++] = '\0';
	}
	return (dst);
}
