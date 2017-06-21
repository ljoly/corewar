/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:58:51 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/27 22:17:59 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print(char *str, int *count, int cas)
{
	ft_putchar(str[0]);
	*count = *count + 1;
	return (cas);
}

int				ft_printf(const char *str, ...)
{
	int			count;
	va_list		ap;
	int			a;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '{' && (a = ft_colours((char*)str, &count)))
			str += a;
		else if (*str != '%')
			str += ft_print((char*)str, &count, 1);
		else
		{
			if (str[1] == '%')
				str += ft_print((char*)str, &count, 2);
			else if ((a = ft_check_format((char*)str)) == 0)
				return (count);
			else
				str = str + ft_printformat((char*)str, &count, ap, a) + 1;
		}
	}
	va_end(ap);
	return (count);
}
