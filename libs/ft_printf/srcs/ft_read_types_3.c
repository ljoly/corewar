/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_types_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:22:57 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/27 20:13:59 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_str(va_list ap, t_info *info)
{
	char	*str2;
	char	*str;

	str2 = (char*)va_arg(ap, void*);
	if (str2 == NULL)
	{
		if (!(str = (char*)malloc(7)))
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
		str = ft_strndup(str2, PREC);
	else
		str = ft_strdup(str2);
	return (str);
}

char	*ft_read_void(va_list ap, t_info *info)
{
	void	*n;
	char	*str;
	char	*s;

	n = va_arg(ap, void*);
	if (!(s = (char*)malloc(3)))
		return (NULL);
	s[0] = '0';
	s[1] = 'x';
	s[2] = '\0';
	if (n == 0 && PREC == 0)
		return (s);
	str = ft_strjoinfree(s, ft_itoa_base((unsigned long long)n, 16));
	return (str);
}

char	*ft_read_ssizet(va_list ap)
{
	ssize_t		n;
	char		*str;

	n = va_arg(ap, ssize_t);
	str = ft_itoa(n);
	return (str);
}
