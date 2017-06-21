/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:45:21 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/31 13:45:22 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconversion(char *c)
{
	if (*c == 's' || *c == 'S' || *c == 'p' || *c == 'c' || *c == 'C')
		return (1);
	if (*c == 'd' || *c == 'D' || *c == 'i' || *c == 'o' || *c == 'O'
			|| *c == 'u' || *c == 'U' || *c == 'x' || *c == 'X' || *c == '%')
		return (2);
	return (0);
}

int		ft_ismodifier(char *str)
{
	int		count;

	count = 0;
	if ((*str == 'h' && str[1] == 'h') || (*str == 'l' && str[1] == 'l'))
		count = 2;
	else if ((*str == 'h' && str[1] != 'h') || (*str == 'l' && str[1] != 'l')
			|| *str == 'j' || *str == 'z')
		count = 1;
	str += count;
	if (!str)
		count = 0;
	return (count);
}

int		ft_isprecision(char *str)
{
	int		count;

	count = 0;
	while (*str == '.')
	{
		count++;
		str++;
	}
	while ((*str >= '0' && *str <= '9') || *str == '*')
	{
		str++;
		count++;
	}
	if (str)
		return (count);
	return (0);
}

int		ft_iswidth(char *str)
{
	int		count;

	count = 0;
	while ((*str >= '0' && *str <= '9') || *str == '*')
	{
		count++;
		str++;
	}
	if (str && count)
		return (count);
	else
		return (0);
}

int		ft_isflag(char *str)
{
	int		count;

	count = 0;
	if (*str == '#' || *str == '-' || *str == '+' || *str == ' ' || *str == '0')
	{
		str++;
		if (str)
			return (1);
	}
	return (0);
}
