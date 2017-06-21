/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_addfirst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:06:18 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:06:19 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clist_addfirst(t_clist list, void *data, size_t size)
{
	t_list	*link;

	if (list)
	{
		link = malloc(sizeof(t_list));
		if (link)
		{
			link->next = NULL;
			link->content = data;
			link->content_size = size;
			if (!*list)
				*list = link;
			link->next = (*list)->next;
			(*list)->next = link;
		}
	}
}
