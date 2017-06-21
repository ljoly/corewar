/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:52:03 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/21 13:44:15 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			init_cor_file(char *asm_file, char **cor_file)
{
	int				len;
	int				fd;

	len = ft_strlen(asm_file);
	*cor_file = ft_memalloc((len + 3) * sizeof(char));
	*cor_file = ft_strncpy(*cor_file, asm_file, len - 2);
	*cor_file = ft_strcat(*cor_file, ".cor");
	fd = -1;
	if ((fd = open(*cor_file, O_TRUNC | O_WRONLY | O_CREAT, 0644)) == -1)
		ft_err(4);
	ft_printf("Writing output program to %s\n", *cor_file);
	return (fd);
}

static void			init_writing(t_binary *file, int fd_s, char *asm_file,
		char **cor_file)
{
	int				fd_cor;

	fd_cor = init_cor_file(asm_file, cor_file);
	write_binary(file, fd_cor);
	close(fd_s);
	close(fd_cor);
}

static void			init_binary_struct(t_binary *file)
{
	ft_bzero(file, sizeof(t_binary));
	file->header.magic = COREWAR_EXEC_MAGIC;
	if (!(file->format.op = (t_op**)ft_memalloc(sizeof(t_op*))) ||
			!(file->format.label = (t_label**)ft_memalloc(sizeof(t_label*))))
		ft_err(5);
}

/*
** Parsing the assembly file using a finite-state machine
*/

void				file_parsing(int fd_s, char *asm_file_name)
{
	t_binary		file;
	t_read			gnl;
	char			*tmp;
	char			*cor_file_name;

	init_binary_struct(&file);
	state_machine(START, NULL, NULL);
	while ((gnl.ret = get_next_line(fd_s, &(gnl.line))) > 0)
	{
		tmp = gnl.line;
		if (!state_machine(USE, &tmp, &file))
		{
			free(gnl.line);
			ft_err(6);
		}
		free(gnl.line);
	}
	if (gnl.ret == -1)
		ft_err(7);
	if (file.header.prog_size > CHAMP_MAX_SIZE)
		ft_err(8);
	if (!state_machine(END, NULL, NULL) || !replace_labels(&file))
		ft_err(6);
	init_writing(&file, fd_s, asm_file_name, &cor_file_name);
	exit(0);
}
