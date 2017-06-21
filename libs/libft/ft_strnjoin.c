/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:12:52 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/09 17:35:57 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		c;

	if (!(join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	c = 0;
	while (s1[c] != '\0')
		join[i++] = s1[c++];
	free((void*)s1);
	c = 0;
	while (s2[c] != '\0')
		join[i++] = s2[c++];
	join[i] = '\0';
	return (join);
}
