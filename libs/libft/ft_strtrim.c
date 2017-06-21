/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:52:03 by bdal-can          #+#    #+#             */
/*   Updated: 2017/01/24 11:19:18 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	int		e;
	int		len;
	int		t;

	if (s == NULL || s[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	e = ft_strlen(s) - 1;
	while (e > 0 && (s[e] == ' ' || s[e] == '\n' || s[e] == '\t'))
		e--;
	len = e - i;
	if (!(trimmed = (char*)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	t = 0;
	while (i != e + 1)
		trimmed[t++] = s[i++];
	trimmed[t] = '\0';
	return (trimmed);
}
