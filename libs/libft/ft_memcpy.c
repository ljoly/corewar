/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:43:16 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 14:11:39 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	char	*copy;
	char	*copy_src;
	size_t	i;

	if (s1 == s2 || n == 0)
		return (s1);
	copy = (char*)s1;
	copy_src = (char*)s2;
	i = 0;
	while (i < n)
	{
		copy[i] = copy_src[i];
		i++;
	}
	return (s1);
}
