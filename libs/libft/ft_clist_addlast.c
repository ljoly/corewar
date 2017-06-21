/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_addlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:06:32 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:06:33 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clist_addlast(t_clist list, void *data, size_t size)
{
	if (list)
	{
		ft_clist_addfirst(list, data, size);
		*list = (*list)->next;
	}
}
