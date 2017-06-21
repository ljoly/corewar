/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:25:13 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 12:25:32 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wcsbytelen(wchar_t *wstr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (wstr[i])
	{
		count += ft_countbyte(wstr[i]);
		i++;
	}
	return (count);
}
