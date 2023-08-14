/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:30:19 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/07 15:26:35 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_CMD_ERR);
}

void	free_arr(char **argv)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (argv[size])
		size++;
	while (i < size)
		free(argv[i++]);
	free(argv);
}

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
		free(matriz[i++]);
	free(matriz);
}

int	ft_open(char *file, int std)
{
	int	fd;

	fd = 0;
	if (std == STDIN)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_error(OPEN_FILE_ERR);
	}
	if (std == 1)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_error(OPEN_FILE_ERR);
	}
	if (fd < 0)
		ft_error(OPEN_FILE_ERR);
	return (fd);
}
