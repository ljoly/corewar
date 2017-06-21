/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:21:25 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 15:08:41 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_display(t_info *info, char *str)
{
	str = ft_addprecision(info, str);
	str = ft_addplusspaceflags(info, str);
	str = ft_addhashflag(info, str);
	if (WIDTH != -1 && C->c && C->unprint == 0 && F->minus)
	{
		ft_putchar(0);
		F->printed = 1;
	}
	str = ft_addwidth(info, str);
	return (str);
}

char	*ft_addplusspaceflags(t_info *info, char *str)
{
	if ((F->plus || F->space) && (C->d))
	{
		if (((str[0] >= '0' && str[0] <= '9') || str[0] == '\0') && F->plus)
			str = ft_pad(1, str, '+', 'l');
		if (((str[0] >= '0' && str[0] <= '9') || str[0] == '\0') && F->space)
			str = ft_pad(1, str, ' ', 'l');
	}
	return (str);
}

char	*ft_addprecision(t_info *info, char *str)
{
	if (PREC != -1 && (C->d || C->o || C->u || C->x || C->xx)
			&& ((str[0] == '-' && (int)ft_strlen(str + 1) < PREC)
				|| (str[0] != '-' && (int)ft_strlen(str) < PREC)))
		str = ft_insertzero(str, PREC);
	else if (PREC > 0 && C->p && PREC > (int)ft_strlen(str) - 2)
		str = ft_widthzerowithhash(str, (PREC - ft_strlen(str) + 2), 2);
	if (PREC == 0 && str[0] == '0' && !(C->p))
		str[0] = '\0';
	return (str);
}

char	*ft_addhashflag(t_info *info, char *str)
{
	char	*zerox;

	if (F->hash)
	{
		if ((C->o) && (F->hash) && str[0] != '0')
			str = ft_insertzero(str, (int)ft_strlen(str) + 1);
		if (((C->xx) || (C->x)) && (!(str[0] == '0' && str[1] == '\0'))
				&& str[0] != '\0')
		{
			if (!(zerox = (char*)malloc(3)))
				return (NULL);
			zerox[0] = '0';
			if ((C->xx))
				zerox[1] = 'X';
			else if ((C->x))
				zerox[1] = 'x';
			zerox[2] = '\0';
			str = ft_strjoinfree(zerox, str);
		}
	}
	return (str);
}

char	*ft_addwidth(t_info *info, char *str)
{
	if (WIDTH != -1)
	{
		if (C->c && C->unprint == 0)
			WIDTH--;
		if ((int)ft_strlen(str) < WIDTH && F->zero == 0 && F->minus == 0)
			str = ft_pad(WIDTH - (int)ft_strlen(str), str, ' ', 'l');
		else if ((int)ft_strlen(str) < WIDTH && F->zero == 0 && F->minus == 1)
			str = ft_pad(WIDTH - (int)ft_strlen(str), str, ' ', 'r');
		else if ((int)ft_strlen(str) < WIDTH && F->zero == 1)
		{
			if (F->hash == 1 && !(C->o))
				str = ft_widthzerowithhash(str, WIDTH - (int)ft_strlen(str), 2);
			else if ((F->plus && C->d) || F->space || str[0] == '-')
				str = ft_widthzerowithhash(str, WIDTH - (int)ft_strlen(str), 1);
			else if (C->p == 1)
				str = ft_pad(WIDTH - (int)ft_strlen(str), str, '0', 'r');
			else
				str = ft_pad(WIDTH - (int)ft_strlen(str), str, '0', 'l');
		}
	}
	return (str);
}
