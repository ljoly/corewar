/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:09:45 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:09:46 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check_argc(int argc, int nb, char *str)
{
	if (argc == nb + 1)
		return (1);
	else if (argc < nb)
		ft_putstr("Not enough parameters\nUsage: ");
	else if (argc > nb)
		ft_putstr("To much parameters\nUsage: ");
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}
