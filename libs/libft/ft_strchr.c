/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:41:24 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/28 20:14:06 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char*)s + i);
}
