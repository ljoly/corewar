/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:06:41 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:09:35 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist		ft_clist_create(void)
{
	t_clist		ret_val;

	ret_val = malloc(sizeof(t_list *));
	if (ret_val)
		*ret_val = NULL;
	return (ret_val);
}
