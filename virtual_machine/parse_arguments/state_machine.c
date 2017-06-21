/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:26:24 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/15 15:43:14 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

int		state_machine(int action, void *data, void *use_on)
{
	static void *state;

	if (action == NEW)
	{
		state = START_STATE;
	}
	else if (action == USE)
	{
		state = ((void *(*)(void*, void*))state)(data, use_on);
		if (state == NULL)
			return (1);
	}
	else if (action == END)
	{
		if (state != FINAL_STATE)
			return (1);
	}
	return (0);
}

void	ft_usage(void)
{
	ft_printf("\n{yel}********************************** USAGE ************");
	ft_printf("**************************{eoc}\n\n ");
	ft_printf("{cyan}-dump N{eoc} --> prints hex dump after N cycles. \n\t\t");
	ft_printf("-It CAN'T be used with any graphic option.\n ");
	ft_printf("{cyan}-v{eoc} --> graphic visualiser in continuous mode. \n");
	ft_printf("\t\t-Press S to start and it runs until the end. \n\t\t");
	ft_printf("-Speed can be increased or decreased using the arrows up and ");
	ft_printf("down.\n {cyan}-p{eoc} --> graphic visualiser in mode step by ");
	ft_printf("step. \n\t\t-Press S for every cycle.\n {cyan}-n N{eoc} ");
	ft_printf("--> can be used only before a valid .cor file. \n\t\t-N ");
	ft_printf("indicates the player number. \n\t\t-It accept all positive num");
	ft_printf("bers and negative numbers EXEPT 0. \n\t\t-The same number");
	ft_printf("can NOT be used for more than one player.\n");
	ft_printf(" {cyan}Max 4 players, minimum 1.\n\n{yel}*******************");
	ft_printf("*********");
	ft_printf("****************************************************\n\n{eoc}");
	exit(0);
}
