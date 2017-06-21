/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:14:19 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/28 10:26:05 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_markflag(char *str, t_info **info)
{
	int		a;

	a = 0;
	while (ft_isflag(str) == 1)
	{
		(*str == '#') ? (*info)->flags->hash = 1 : 0;
		if (*str == '-')
			(*info)->flags->minus = 1;
		else if (*str == '+')
			(*info)->flags->plus = 1;
		else if (*str == ' ')
			(*info)->flags->space = 1;
		else if (*str == '0')
			(*info)->flags->zero = 1;
		a++;
		str++;
	}
	return (a);
}

int			ft_markwidth(char *str, t_info **info)
{
	int		i;

	i = 0;
	(*info)->width = ft_atoi(str);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
	{
		if (str[i] == '*')
		{
			(*info)->flags->wstar = 1;
			(*info)->width = ft_atoi(str + 1);
		}
		i++;
	}
	if (str[i - 1] == '*')
		(*info)->flags->wstar = 2;
	return (i);
}

int			ft_markprecision(char *str, t_info **info)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (*str == '.')
	{
		str++;
		i++;
	}
	(*info)->precision = ft_atoi(str);
	while ((str[c] >= '0' && str[c] <= '9') || str[c] == '*')
	{
		if (str[c] == '*')
		{
			(*info)->flags->pstar = 1;
			(*info)->precision = ft_atoi(str + 1);
		}
		c++;
	}
	if (str[c - 1] == '*')
		(*info)->flags->pstar = 2;
	i += c;
	return (i);
}

int			ft_markmodifier(char *str, t_info **info)
{
	int		a;

	a = 1;
	if (*str == 'h' && str[1] == 'h')
	{
		MM->hh = 1;
		a++;
	}
	else if (*str == 'h' && str[1] != 'h')
		MM->h = 1;
	else if (*str == 'l' && str[1] == 'l')
	{
		MM->ll = 1;
		a++;
	}
	else if (*str == 'l' && str[1] != 'l')
		MM->l = 1;
	else if (*str == 'j')
		MM->j = 1;
	else if (*str == 'z')
		MM->z = 1;
	return (a);
}

void		ft_markconversion(char c, t_info **info)
{
	if (c == 's' || c == 'S')
		(*info)->conv->s = 1;
	else if (c == 'p')
		(*info)->conv->p = 1;
	else if (c == 'd' || c == 'D' || c == 'i')
		(*info)->conv->d = 1;
	else if (c == 'o' || c == 'O')
		(*info)->conv->o = 1;
	else if (c == 'u' || c == 'U')
		(*info)->conv->u = 1;
	else if (c == 'x')
		(*info)->conv->x = 1;
	else if (c == 'X')
		(*info)->conv->xx = 1;
	else if (c == 'C' || c == 'c')
		(*info)->conv->c = 1;
	else if (c == '%')
		(*info)->conv->perc = 1;
	if (c == 'S' || c == 'C' || c == 'U' || c == 'O' || c == 'D')
		MM->l = 1;
}
