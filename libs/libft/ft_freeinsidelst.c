/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeinsidelst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:56:04 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/17 10:56:19 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeinsidelst(void *content, size_t content_size)
{
	if (content == NULL)
		return ;
	free(content);
	content_size = 0;
}
