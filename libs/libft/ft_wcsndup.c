/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:30:11 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 12:25:23 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wcsndup(wchar_t *str, int byte)
{
	wchar_t		*copy;
	int			i;
	int			count;

	count = 0;
	if (!(copy = (wchar_t*)malloc(sizeof(wchar_t) * (byte + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && count + ft_countbyte(str[i]) <= byte)
	{
		copy[i] = str[i];
		count += ft_countbyte(str[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
