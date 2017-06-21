/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_rmfirst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:07:33 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:07:35 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clist_rmfirst(t_clist list)
{
	t_list	*to_rm;

	if (list)
	{
		if (*list)
		{
			to_rm = (*list)->next;
			(*list)->next = to_rm->next;
			free(to_rm);
			if (*list == to_rm)
				*list = NULL;
		}
	}
}
