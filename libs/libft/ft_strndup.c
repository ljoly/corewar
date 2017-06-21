/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:58:55 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/04 15:48:05 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!(copy = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (s[++i] && i < n)
		copy[i] = s[i];
	copy[i] = '\0';
	return (copy);
}
