/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:02:24 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/22 17:56:02 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_calc(unsigned long long tmp, int a, char *str, int base)
{
	const char		*b = "0123456789abcdef";

	while (tmp)
	{
		str[--a] = b[tmp % base];
		tmp /= base;
	}
	return (str);
}

char			*ft_itoa_base(unsigned long long nb, int base)
{
	char					*str;
	unsigned long long		tmp;
	int						a;

	if (base < 2 || base > 16)
		return (NULL);
	tmp = ABS(nb);
	a = 1;
	while ((nb = nb / base))
		a++;
	if (!(str = (char *)malloc(a + 1)))
		return (NULL);
	str[a] = '\0';
	(tmp == 0) ? str[0] = '0' : 0;
	str = ft_calc(tmp, a, str, base);
	return (str);
}
