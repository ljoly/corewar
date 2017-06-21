/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:17:11 by bdal-can          #+#    #+#             */
/*   Updated: 2017/01/23 20:50:31 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict a, const void *restrict b, int c, size_t n)
{
	unsigned char	*copy_src;
	unsigned char	*copy_dest;
	size_t			i;

	if (a == b)
		return (a);
	copy_src = (unsigned char*)b;
	copy_dest = (unsigned char*)a;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		copy_dest[i] = copy_src[i];
		if (copy_src[i] == c)
			return (a + i + 1);
		i++;
	}
	return (NULL);
}
