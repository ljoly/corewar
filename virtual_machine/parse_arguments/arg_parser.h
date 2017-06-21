/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:28:02 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:12:47 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

# include "../vm.h"

# define USAGE_ERR "To display usage, run the program with the flag -h\n"
# define CT "Can't read file <"
# define UE "USAGE ERROR.\n"

# define START_STATE &(state_a)
# define FINAL_STATE &(state_e)

# define NEW 0
# define USE 1
# define END 2

typedef struct s_env	t_env;

/*
** arg_parser.c
*/
t_env	*ft_arg_parser(int ac, char **av);
void	ft_free_env_exit(t_env *env, char *message);

/*
** state_machine.c
*/
int		state_machine(int action, void *data, void *use_on);
void	ft_usage(void);

/*
** state functions
*/
int		ft_addplayer(char *str, t_env *env, int tmp);
int		ft_iscor(char *str);
void	*state_a(void *data, void *act_on);
void	*state_b(void *data, void *act_on);
void	*state_c(void *data, void *act_on);
void	*state_d(void *data, void *act_on);
void	*state_e(void *data, void *act_on);

#endif
