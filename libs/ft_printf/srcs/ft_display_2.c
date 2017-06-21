/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:00:42 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/28 11:50:25 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_insertzero(char *s1, int prec)
{
	char	*str;
	int		len;
	int		i;
	int		h;
	int		z;

	i = 0;
	if (s1[0] == '-')
		i = 1;
	len = prec + i;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	z = 0;
	if (i == 1)
		str[0] = '-';
	h = i;
	while (z++ < (len - (int)ft_strlen(s1)))
		str[i++] = '0';
	while (s1[h] != '\0')
		str[i++] = s1[h++];
	free((void*)s1);
	return (str);
}

char	*ft_pad(int spaces, char *str, char pad, char side)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(spaces + 1)))
		return (NULL);
	s[spaces] = '\0';
	while (i < spaces)
		s[i++] = pad;
	if (side == 'l')
		str = ft_strjoinfree(s, str);
	else if (side == 'r')
		str = ft_strjoinfree(str, s);
	return (str);
}

char	*ft_widthzerowithhash(char *str, int zeros, int margin)
{
	char	*newstr;
	int		z;
	int		i;
	int		c;

	if (!(newstr = (char*)malloc(ft_strlen(str) + zeros + 1)))
		return (NULL);
	newstr[ft_strlen(str) + zeros] = '\0';
	i = -1;
	z = 0;
	while (++i != margin)
		newstr[i] = str[i];
	c = margin;
	while (++z <= zeros)
		newstr[i++] = '0';
	while (c != (int)ft_strlen(str))
		newstr[i++] = str[c++];
	free((void*)str);
	return (newstr);
}

void	ft_correction(t_info **info)
{
	if ((*info)->flags->wstar == 2)
		(*info)->width = (*info)->flags->wstar_pri;
	if ((*info)->flags->pstar == 2)
		(*info)->precision = (*info)->flags->pstar_pri;
	if ((*info)->flags->wstar == 2 && (*info)->width < 0)
	{
		(*info)->flags->minus = 1;
		(*info)->width = -(*info)->width;
	}
	if ((*info)->flags->pstar == 2 && (*info)->precision < 0)
		(*info)->precision = -1;
	if ((*info)->width == -1 && (*info)->flags->zero == 1)
		(*info)->flags->zero = 0;
	if ((*info)->width == -1 && (*info)->flags->minus == 1)
		(*info)->flags->minus = 0;
	if (((*info)->flags->minus) && ((*info)->flags->zero))
		(*info)->flags->zero = 0;
	if (((*info)->flags->plus) && ((*info)->flags->space))
		(*info)->flags->space = 0;
	if ((*info)->precision != -1 && (*info)->width != -1 && (*info)->flags->zero
			&& CC->c == 0 && CC->s == 0 && CC->perc == 0)
		(*info)->flags->zero = 0;
}
