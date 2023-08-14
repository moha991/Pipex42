/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:38:46 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/08 10:09:21 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	system_exec(char *cmdtemplate)
// {
// 	FILE	*fp;
// 	char	output[1024];
// 	size_t	n;

// 	fp = popen(cmdtemplate, "r");
// 	if (fp == NULL)
// 	{
// 		ft_putstr_fd("Error opening command", 2);
// 		ft_putstr_fd(cmdtemplate, 2);
// 		return ;
// 	}
// 	n = fread(output, 1, sizeof(output), fp);
// 	output[n] = '\0';
// 	ft_putstr_fd(output, 2);
// }

// static void	exit_checks(void)
// {
// 	char	cmdtemplate[1024];

// 	ft_putstr_fd("\n\n******************************************\n", 2);
// 	ft_putstr_fd("Open fds:\n", 2);
// 	sprintf(cmdtemplate, "lsof -p %d | grep CHR", getpid());
// 	system_exec(cmdtemplate);
// 	ft_putstr_fd("\nLeaks:\n", 2);
// 	sprintf(cmdtemplate, "leaks %d", getpid());
// 	system_exec(cmdtemplate);
// 	ft_putstr_fd("******************************************\n", 2);
// }

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv, envp);
	if (argc > 5)
		exit(EXIT_FAILURE);
	return (0);
}
