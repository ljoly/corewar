/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:52:14 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/28 11:04:56 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info		*ft_create_info(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	if (!(info->flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	if (!(info->mod = (t_mod*)malloc(sizeof(t_mod))))
		return (NULL);
	if (!(info->conv = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	ft_initialise(&info);
	return (info);
}

void		ft_free_info(t_info **info)
{
	free((void*)(*info)->flags);
	free((void*)(*info)->mod);
	free((void*)(*info)->conv);
	free((void*)*info);
}

static void	ft_initialise2(t_info **info)
{
	(*info)->conv->s = 0;
	(*info)->conv->p = 0;
	(*info)->conv->d = 0;
	(*info)->conv->o = 0;
	(*info)->conv->u = 0;
	(*info)->conv->x = 0;
	(*info)->conv->xx = 0;
	(*info)->conv->c = 0;
	(*info)->conv->perc = 0;
	(*info)->conv->unprint = -1;
	(*info)->conv->extra = 0;
}

void		ft_initialise(t_info **info)
{
	(*info)->flags->hash = 0;
	(*info)->flags->minus = 0;
	(*info)->flags->plus = 0;
	(*info)->flags->space = 0;
	(*info)->flags->zero = 0;
	(*info)->flags->wstar = 0;
	(*info)->flags->pstar = 0;
	(*info)->flags->wstar_pri = 0;
	(*info)->flags->pstar_pri = 0;
	(*info)->flags->printed = 0;
	(*info)->mod->hh = 0;
	(*info)->mod->h = 0;
	(*info)->mod->l = 0;
	(*info)->mod->ll = 0;
	(*info)->mod->j = 0;
	(*info)->mod->z = 0;
	(*info)->width = -1;
	(*info)->precision = -1;
	ft_initialise2(info);
}
