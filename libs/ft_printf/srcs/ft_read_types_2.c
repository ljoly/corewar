/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_types_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:22:34 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/27 20:13:43 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_signchar(va_list ap)
{
	signed char		n;
	char			*str;

	n = (signed char)va_arg(ap, int);
	str = ft_itoa(n);
	return (str);
}

char	*ft_read_short(va_list ap)
{
	short	n;
	char	*str;

	n = (short)va_arg(ap, int);
	str = ft_itoa(n);
	return (str);
}

char	*ft_read_long(va_list ap)
{
	long	n;
	char	*str;

	n = va_arg(ap, long);
	str = ft_itoa(n);
	return (str);
}

char	*ft_read_longlong(va_list ap)
{
	long long	n;
	char		*str;

	n = va_arg(ap, long long);
	str = ft_itoa(n);
	return (str);
}

char	*ft_read_sizet(va_list ap, t_info **info)
{
	size_t		n;
	char		*str;

	n = va_arg(ap, size_t);
	if (CC->u)
		str = ft_itoa_base(n, 10);
	if (CC->o)
		str = ft_itoa_base(n, 8);
	if (CC->xx || CC->x)
		str = ft_itoa_base(n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}
