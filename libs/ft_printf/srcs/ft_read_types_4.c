/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_types_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:49:46 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 15:07:37 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_read_wint(va_list ap, t_info *info)
{
	wchar_t		*str;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	if (c == 0)
		C->unprint = c;
	return (str);
}

wchar_t	*ft_read_wcharstr(va_list ap, t_info *info)
{
	wchar_t		*str;
	wchar_t		*str2;

	str2 = va_arg(ap, wchar_t*);
	if (str2 == NULL)
	{
		if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * 7)))
			return (NULL);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		str[6] = '\0';
		if (PREC != -1)
			str[PREC] = '\0';
		return (str);
	}
	if (PREC != -1)
		str = ft_wcsndup(str2, PREC);
	else
		str = ft_wcsdup(str2);
	return (str);
}

char	*ft_read_perc(void)
{
	char	*str;

	if (!(str = (char*)malloc(2)))
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
