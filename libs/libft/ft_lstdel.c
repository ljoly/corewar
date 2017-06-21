/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavenan <tlavenan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:32:34 by tlavenan          #+#    #+#             */
/*   Updated: 2017/05/30 13:59:54 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*blst;

	if (alst && del)
	{
		if (*alst)
		{
			while ((*alst)->next)
			{
				blst = *alst;
				*alst = (*alst)->next;
				ft_lstdelone(&blst, del);
			}
			ft_lstdelone(alst, del);
		}
	}
}
