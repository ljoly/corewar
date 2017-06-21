/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree1st.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:44 by bdal-can          #+#    #+#             */
/*   Updated: 2017/04/20 18:34:39 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree1st(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		c;

	if (!s1)
		s1 = ft_strnew(0);
	if (!(join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	c = 0;
	while (s1[c] != '\0')
		join[i++] = s1[c++];
	c = 0;
	while (s2[c] != '\0')
		join[i++] = s2[c++];
	join[i] = '\0';
	free((void*)s1);
	return (join);
}
