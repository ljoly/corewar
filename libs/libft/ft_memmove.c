/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:54:07 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/17 18:11:00 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*copy_dest;
	char	*copy_src;

	copy_dest = (char*)dst;
	copy_src = (char*)src;
	i = 0;
	if (src <= dst)
		while (len != 0)
		{
			copy_dest[len - 1] = copy_src[len - 1];
			len--;
		}
	if (src > dst)
		while (i < len)
		{
			copy_dest[i] = copy_src[i];
			i++;
		}
	return (dst);
}
