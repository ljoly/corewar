/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:02:44 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:13:52 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mall_error(void)
{
	ft_putstr_fd("MALLOC ERROR\n", 2);
	exit(0);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dest;

	if (!(dest = (t_list *)malloc(sizeof(t_list))))
		mall_error();
	if (content_size + 1 < content_size)
		return (NULL);
	if (dest)
	{
		dest->content = NULL;
		dest->next = NULL;
		dest->content_size = 0;
		if (content && content_size)
		{
			if (!(dest->content = malloc(content_size)))
				mall_error();
			if (dest->content)
				ft_memcpy(dest->content, content, content_size);
			dest->content_size = content_size;
		}
	}
	return (dest);
}
