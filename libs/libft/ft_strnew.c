/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:10:49 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/30 18:46:28 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = (char*)malloc(size + 1)))
	{
		while (i < size)
			new[i++] = '\0';
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
