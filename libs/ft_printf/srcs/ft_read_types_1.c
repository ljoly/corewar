/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_types_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:23:37 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/28 11:50:45 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_int(va_list ap, t_info **info)
{
	int		n;
	char	*str;

	n = va_arg(ap, int);
	if (CC->d)
		str = ft_itoa(n);
	if (CC->o)
		str = ft_itoa_base((unsigned int)n, 8);
	if (CC->u)
		str = ft_itoa_base((unsigned int)n, 10);
	if (CC->x || CC->xx)
		str = ft_itoa_base((unsigned int)n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if (CC->c)
	{
		str = ft_strnew(1);
		str[0] = (unsigned char)n;
		if ((unsigned char)n == 0)
			CC->unprint = n;
	}
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}

char	*ft_read_unschar(va_list ap, t_info **info)
{
	unsigned char	n;
	char			*str;

	n = (unsigned char)va_arg(ap, int);
	if (CC->o)
		str = ft_itoa_base(n, 8);
	if (CC->u)
		str = ft_itoa_base(n, 10);
	if (CC->xx || CC->x)
		str = ft_itoa_base(n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}

char	*ft_read_unsshort(va_list ap, t_info **info)
{
	unsigned short		n;
	char				*str;

	n = (unsigned short)va_arg(ap, int);
	if (CC->o)
		str = ft_itoa_base(n, 8);
	if (CC->u)
		str = ft_itoa_base(n, 10);
	if (CC->xx || CC->x)
		str = ft_itoa_base(n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}

char	*ft_read_unslong(va_list ap, t_info **info)
{
	unsigned long	n;
	char			*str;

	n = (unsigned long)va_arg(ap, long long);
	if (CC->o)
		str = ft_itoa_base(n, 8);
	if (CC->u)
		str = ft_itoa_base(n, 10);
	if (CC->xx || CC->x)
		str = ft_itoa_base(n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}

char	*ft_read_unslonglong(va_list ap, t_info **info)
{
	unsigned long long		n;
	char					*str;

	n = va_arg(ap, unsigned long long);
	if (CC->o)
		str = ft_itoa_base(n, 8);
	if (CC->u)
		str = ft_itoa_base(n, 10);
	if (CC->xx || CC->x)
		str = ft_itoa_base(n, 16);
	if (CC->xx)
		ft_capitalise(str);
	if ((CC->x || CC->xx) && n == 0)
		(*info)->flags->hash = 0;
	return (str);
}
