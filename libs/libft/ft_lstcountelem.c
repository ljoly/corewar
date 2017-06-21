/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountelem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:32:09 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/07 17:17:55 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcountelem(t_list *list)
{
	int		count;

	if (!list)
		return (0);
	count = 1;
	while (list->next)
	{
		count++;
		list = list->next;
	}
	return (count);
}
