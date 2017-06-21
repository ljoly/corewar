/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:15:02 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/21 13:37:22 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_err(int err_code)
{
	if (err_code == 1)
		ft_putendl_fd("ERROR: no parameter", 2);
	else if (err_code == 2)
		ft_putendl_fd("ERROR: too many parameters", 2);
	else if (err_code == 3)
		ft_putendl_fd("ERROR: invalid file", 2);
	else if (err_code == 4)
		ft_putendl_fd("ERROR: while opening file", 2);
	else if (err_code == 5)
		ft_putendl_fd("ERROR: could not malloc", 2);
	else if (err_code == 6)
		ft_putendl_fd("ERROR: wrong champion format", 2);
	else if (err_code == 7)
		ft_putendl_fd("ERROR: while reading file", 2);
	else if (err_code == 8)
		ft_putendl_fd("ERROR: champion is bigger than authorized max size", 2);
	if (err_code == 1 || err_code == 2)
		ft_putendl_fd("Usage: asm [path_to_file]", 2);
	exit(-1);
}

int				main(int argc, char **argv)
{
	int			len;
	int			fd_s;

	fd_s = -1;
	if (argc < 2)
		ft_err(1);
	else if (argc > 2)
		ft_err(2);
	else if ((len = ft_strlen(argv[1])) <= 2 ||
			argv[1][len - 2] != '.' || argv[1][len - 1] != 's')
		ft_err(3);
	else if ((fd_s = open(argv[1], O_RDONLY)) == -1)
		ft_err(4);
	file_parsing(fd_s, argv[1]);
	return (0);
}
