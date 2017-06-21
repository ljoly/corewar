/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkandmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:24:46 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/28 10:24:33 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_clearmodifiers(t_info **info)
{
	if ((MM->ll || MM->j) && (MM->l || MM->h || MM->hh || MM->z))
	{
		MM->l = 0;
		MM->h = 0;
		MM->hh = 0;
	}
	if (MM->l && (MM->h || MM->hh))
	{
		MM->h = 0;
		MM->hh = 0;
	}
	if (MM->h && MM->hh)
		MM->hh = 0;
	if (MM->z && (MM->hh || MM->h))
	{
		MM->hh = 0;
		MM->h = 0;
	}
}

static int		ft_calling(char *str, t_info **info)
{
	int		a;
	int		count;
	int		i;

	count = 0;
	a = 0;
	i = 1;
	while (a != 0 || i == 1)
	{
		i = 0;
		if ((ft_isflag(str)))
			a = ft_markflag(str, info);
		else if ((ft_iswidth(str)))
			a = ft_markwidth(str, info);
		else if (ft_isprecision(str))
			a = ft_markprecision(str, info);
		else if (ft_ismodifier(str))
			a = ft_markmodifier(str, info);
		else
			a = 0;
		str += a;
		count += a;
	}
	return (count);
}

int				ft_getinfo(char *str, t_info **info, int norm)
{
	int		a;
	int		count;

	a = 0;
	str++;
	count = ft_calling(str, info);
	str += count;
	count += 1;
	if (norm == 1 || ((norm == -1 && (*info)->flags->minus)
				&& (*info)->width > 0))
	{
		if (norm == 1)
			ft_markconversion(*str, info);
		else
			CC->extra = str[0];
		count++;
	}
	ft_clearmodifiers(info);
	return (count);
}

static char		*ft_gettype2(va_list ap, t_info *info)
{
	char	*str;

	if (C->p)
		str = ft_read_void(ap, info);
	else if (C->d && M->hh)
		str = ft_read_signchar(ap);
	else if (C->d && M->h)
		str = ft_read_short(ap);
	else if (C->d && M->l)
		str = ft_read_long(ap);
	else if (C->d && (M->ll || M->j))
		str = ft_read_longlong(ap);
	else if (C->d && M->z)
		str = ft_read_ssizet(ap);
	else
		str = ft_read_perc();
	return (str);
}

char			*ft_gettype(va_list ap, t_info **info)
{
	char	*str;

	if ((*info)->flags->wstar)
		(*info)->flags->wstar_pri = va_arg(ap, int);
	if ((*info)->flags->pstar)
		(*info)->flags->pstar_pri = va_arg(ap, int);
	ft_correction(info);
	if (NOMOD && (CC->d || CC->o || CC->u || CC->x || CC->xx || CC->c))
		str = ft_read_int(ap, info);
	else if (CC->s && NOMOD)
		str = ft_read_str(ap, *info);
	else if (CC->p || CC->d || CC->perc)
		str = ft_gettype2(ap, *info);
	else if ((CC->o || CC->u || CC->x || CC->xx) && MM->hh)
		str = ft_read_unschar(ap, info);
	else if ((CC->o || CC->u || CC->x || CC->xx) && MM->h)
		str = ft_read_unsshort(ap, info);
	else if ((CC->o || CC->u || CC->x || CC->xx) && MM->l)
		str = ft_read_unslong(ap, info);
	else if ((CC->o || CC->u || CC->x || CC->xx) && (MM->ll || MM->j))
		str = ft_read_unslonglong(ap, info);
	else
		str = ft_read_sizet(ap, info);
	return (str);
}
