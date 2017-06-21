/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours_and_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:09:24 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 15:09:25 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_recursive_check(char *str)
{
	int		a;
	int		ver;
	int		i;

	i = 1;
	ver = 0;
	a = 0;
	while (a != 0 || i == 1)
	{
		i = 0;
		if ((a = ft_isflag(str)))
			str += a;
		else if ((a = ft_iswidth(str)))
			str += a;
		else if ((a = ft_isprecision(str)))
			str += a;
		else if ((a = ft_ismodifier(str)))
			str += a;
		else
			a = 0;
		ver += a;
	}
	return (ver);
}

int				ft_check_format(char *str)
{
	int		ver;

	str++;
	ver = ft_recursive_check(str);
	str += ver;
	if (!str)
		return (0);
	else if (ft_isconversion(str))
		return (1);
	else
		return (-1);
}

static char		*ft_check_colour(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) >= 5 && ft_strncmp("{red}", str, 5) == 0)
		return ("\x1B[31m");
	if (ft_strlen(str) >= 5 && ft_strncmp("{mag}", str, 5) == 0)
		return ("\x1B[35m");
	if (ft_strlen(str) >= 5 && ft_strncmp("{yel}", str, 5) == 0)
		return ("\x1B[33m");
	if (ft_strlen(str) >= 5 && ft_strncmp("{eoc}", str, 5) == 0)
		return ("\x1B[0m");
	if (ft_strlen(str) >= 6 && ft_strncmp("{cyan}", str, 6) == 0)
		return ("\x1B[36m");
	if (ft_strlen(str) >= 6 && ft_strncmp("{blue}", str, 6) == 0)
		return ("\x1B[34m");
	if (ft_strlen(str) >= 7 && ft_strncmp("{white}", str, 7) == 0)
		return ("\x1B[37m");
	if (ft_strlen(str) >= 7 && ft_strncmp("{green}", str, 7) == 0)
		return ("\x1B[32m");
	return (NULL);
}

int				ft_colours(char *str, int *count)
{
	int		i;

	if (ft_strlen(str) >= 3 && str[1] == '%' && str[2] == '}')
	{
		ft_putstr("{}");
		*count = *count + 2;
		return (3);
	}
	if (ft_check_colour(str) == NULL)
		return (0);
	else
	{
		*count = *count + (int)ft_strlen(ft_check_colour(str));
		ft_putstr(ft_check_colour(str));
	}
	i = 0;
	while (str[i] != '}')
		i++;
	return (i + 1);
}
