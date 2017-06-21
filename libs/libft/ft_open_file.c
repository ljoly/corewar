/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:20:50 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:20:51 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int					ft_open_file(char *path, int flag, int *fd)
{
	*fd = 0;
	if (path)
		*fd = open(path, flag, 0644);
	if (*fd == -1)
	{
		ft_putstr("Error during oppening : ");
		ft_putstr(path);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
