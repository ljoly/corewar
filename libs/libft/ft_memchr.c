/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:46:25 by bdal-can          #+#    #+#             */
/*   Updated: 2017/01/23 16:31:52 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == c)
			return ((void*)(&((unsigned char*)s)[i]));
		i++;
	}
	return (NULL);
}
