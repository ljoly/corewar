/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:14:41 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/27 10:16:27 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../libft/libft.h"

# define C info->conv
# define CC (*info)->conv
# define M info->mod
# define MM (*info)->mod
# define F info->flags
# define PREC info->precision
# define WIDTH info->width
# define NOMOD (!(MM->hh || MM->h || MM->l || MM->ll || MM->z || MM->j))
# define ABS(x) (x < 0) ? -x : x
# define S str[i]

typedef struct s_flag	t_flags;
typedef struct s_mod	t_mod;
typedef struct s_info	t_info;
typedef struct s_conv	t_conv;

struct	s_flag
{
	int		hash;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		wstar;
	int		pstar;
	int		wstar_pri;
	int		pstar_pri;
	int		printed;
};

struct	s_mod
{
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
};
struct	s_conv
{
	int		s;
	int		p;
	int		d;
	int		o;
	int		u;
	int		x;
	int		xx;
	int		c;
	int		perc;
	int		unprint;
	wchar_t	extra;
};
struct	s_info
{
	t_flags		*flags;
	int			width;
	int			precision;
	t_mod		*mod;
	t_conv		*conv;
};

/*
** ft_printf.c
*/
int		ft_printf(const char *str, ...);

/*
** ft_print_format.c
*/
int		ft_printformat(char *whole, int *count, va_list ap, int normal);

/*
** ft_checkandmark.c
*/
int		ft_check_arg(char *str);
int		ft_getinfo(char *str, t_info **info, int normal);
char	*ft_gettype(va_list ap, t_info **info);

/*
** ft_check_functions.c
*/
int		ft_isflag(char *str);
int		ft_iswidth(char *str);
int		ft_isprecision(char *str);
int		ft_ismodifier(char *str);
int		ft_isconversion(char *c);
int		ft_check_format(char *str);
int		ft_recursive_check(char *str);

/*
** ft_init_info.c
*/
t_info	*ft_create_info(void);
void	ft_free_info(t_info **info);
void	ft_initialise(t_info **info);

/*
** ft_get_info.c
*/
int		ft_markflag(char *str, t_info **info);
int		ft_markwidth(char *str, t_info **info);
int		ft_markprecision(char *str, t_info **info);
int		ft_markmodifier(char *str, t_info **info);
void	ft_markconversion(char c, t_info **info);

/*
** ft_read_types_1.c
*/
char	*ft_read_int(va_list ap, t_info **info);
char	*ft_read_unschar(va_list ap, t_info **info);
char	*ft_read_unsshort(va_list ap, t_info **info);
char	*ft_read_unslong(va_list ap, t_info **info);
char	*ft_read_unslonglong(va_list ap, t_info **info);

/*
** ft_read_types_2.c
*/
char	*ft_read_signchar(va_list ap);
char	*ft_read_short(va_list ap);
char	*ft_read_long(va_list ap);
char	*ft_read_longlong(va_list ap);
char	*ft_read_sizet(va_list ap, t_info **info);

/*
** ft_read_types_3.c
*/
char	*ft_read_uintmax(va_list ap, t_info *info);
char	*ft_read_intmax(va_list ap);
char	*ft_read_str(va_list ap, t_info *info);
char	*ft_read_void(va_list ap, t_info *info);
char	*ft_read_ssizet(va_list ap);

/*
** ft_read_types_4.c
*/
wchar_t	*ft_read_wint(va_list ap, t_info *info);
wchar_t	*ft_read_wcharstr(va_list ap, t_info *info);
char	*ft_read_perc(void);

/*
** ft_display.c
*/
char	*ft_display(t_info *info, char *str);
char	*ft_addplusspaceflags(t_info *info, char *str);
char	*ft_addprecision(t_info *info, char *str);
char	*ft_addhashflag(t_info *info, char *str);
char	*ft_addwidth(t_info *info, char *str);

/*
** ft_display_2.c
*/
char	*ft_insertzero(char *s1, int prec);
char	*ft_pad(int spaces, char *str, char pad, char side);
char	*ft_widthzerowithhash(char *str, int zeros, int margin);
void	ft_correction(t_info **info);

/*
** ft_colours_and_other.c
*/
int		ft_recursive_check(char *str);
int		ft_check_format(char *str);
int		ft_colours(char *str, int *count);

#endif
