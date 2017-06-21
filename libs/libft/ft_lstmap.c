/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavenan <tlavenan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:34:34 by tlavenan          #+#    #+#             */
/*   Updated: 2014/12/17 14:49:14 by tlavenan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;
	t_list	*current;

	if (!f || !lst)
		return (NULL);
	dest = f(lst);
	lst = lst->next;
	current = dest;
	while (lst && current)
	{
		current->next = f(lst);
		current = current->next;
		lst = lst->next;
	}
	if (current)
		current->next = NULL;
	return (dest);
}
