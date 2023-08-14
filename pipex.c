/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:58 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/08 09:15:32 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **cmd, char **envp)
{
	int		fidp[2];
	int		status;
	pid_t	pid;

	pid = pipe(fidp);
	if (pipe(fidp) < 0)
	{
		ft_error(PIPE_ERR);
		exit(EXIT_FAILURE);
	}
	if (pid == -1)
		perror("Error");
	first_process_child(fidp, cmd, envp);
	secund_process_child(fidp, cmd, envp);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	if (argc == 0)
// 	{
// 		pipex(argv, envp);
// 		printf("%s\n",envp);
// 	}
// 	return (0);
// }