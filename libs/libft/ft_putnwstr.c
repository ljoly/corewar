/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:19:59 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 12:24:49 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putnwstr(wchar_t *str, int byte)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && byte > ft_countbyte(str[i]) + count)
	{
		count += ft_putwchar(str[i]);
		i++;
	}
	return (count);
}
