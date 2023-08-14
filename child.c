/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:14:33 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/08 10:05:09 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process_child(int *fd, char **argv, char **env)
{
	pid_t	pidc;
	int		fd_input;

	pidc = fork();
	if (pidc < 0)
		ft_error(FORK_ERR);
	if (pidc == 0)
	{
		fd_input = open(argv[1], O_RDONLY, 0644);
		if (fd_input < 0)
			ft_error(OPEN_FILE_ERR);
		dup2(fd_input, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd_input);
		ft_exec(argv[2], env);
	}
	close(fd[STDOUT]);
}

void	secund_process_child(int *fd, char **argv, char **env)
{
	pid_t	pidc2;
	int		fd_ouput;

	pidc2 = fork();
	if (pidc2 < 0)
		ft_error(FORK_ERR);
	else if (pidc2 == 0)
	{
		fd_ouput = open(argv[4], STDIN | O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd_ouput < 0)
			ft_error(OPEN_FILE_ERR);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_ouput, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd_ouput);
		ft_exec(argv[3], env);
	}
	close(fd[STDIN]);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	// atexit(exit_checks);
// 	if (argc == 0 )
// 	{
// 	first_process_child(argc, "ls",envp);
// 	printf("%s\n",envp);
// 	}
// 	return (0);
// }
