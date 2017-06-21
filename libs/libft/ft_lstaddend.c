/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:25:54 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:22:50 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **list, t_list *new)
{
	t_list *copy;

	copy = *list;
	if (!list || !new)
		return ;
	while (copy->next)
		copy = copy->next;
	copy->next = new;
	new->next = NULL;
}
