/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:59:54 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 12:56:27 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(char *str)
{
	int		ver;

	str++;
	ver = ft_recursive_check(str);
	str += ver;
	if (ft_isconversion(str))
		return (ver + 1);
	else
		return (ver);
}

static void		ft_abnormal(t_info *info, int *count, int *incr)
{
	char	c;
	int		i;

	i = 0;
	if (WIDTH > 0)
	{
		if (info->flags->zero == 1)
			c = '0';
		else
			c = ' ';
		if (F->minus)
		{
			*incr = *incr + 1;
			ft_putwchar(C->extra);
		}
		while (i++ != info->width - 1)
			write(1, &c, 1);
		*count = *count + info->width - 1 + F->minus;
	}
}

static void		ft_wchars(va_list ap, t_info *info, int *count, int i)
{
	wchar_t		*str;
	char		c;

	str = (((C->s)) ? ft_read_wcharstr(ap, info) : ft_read_wint(ap, info));
	if (WIDTH != -1 && WIDTH > ft_wcsbytelen(str))
	{
		*count += WIDTH - ft_wcsbytelen(str);
		c = (((F->zero)) ? '0' : ' ');
		if (F->minus == 0)
		{
			while (i++ < WIDTH - ft_wcsbytelen(str))
				ft_putchar(c);
			*count += ft_putwstr(str);
		}
		else
		{
			*count += ft_putwstr(str);
			while (i++ < WIDTH - ft_wcsbytelen(str))
				ft_putchar(c);
		}
	}
	else
		*count += ft_putwstr(str);
	free((void*)str);
}

int				ft_printformat(char *whole, int *count, va_list ap, int normal)
{
	t_info		*info;
	char		*str;
	int			incr;

	info = ft_create_info();
	ft_getinfo(whole, &info, normal);
	incr = ft_count(whole);
	if (normal == -1)
		ft_abnormal(info, count, &incr);
	else if ((C->s || C->c) && (M->l))
		ft_wchars(ap, info, count, 0);
	else
	{
		str = ft_display(info, ft_gettype(ap, &info));
		ft_putstr(str);
		*count = *count + ft_strlen(str) + F->printed;
		free((void*)str);
	}
	if (C->c && C->unprint >= 0 && F->printed == 0)
	{
		*count += 1;
		ft_putchar((char)C->unprint);
	}
	ft_free_info(&info);
	return (incr);
}
