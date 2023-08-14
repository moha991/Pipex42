/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:25:51 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/08 10:13:37 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
			{
				perror(MEM_ERR);
				exit(EXIT_FAILURE);
			}
			return (paths);
		}
		i++;
	}
	ft_error(ENV_PATH_ERR);
	return (0);
}

char	*add_path(char *cmd, char **env)
{
	char	*path_slash;
	char	*path_scmd;
	char	**envp;
	int		i;

	envp = find_path(env);
	if (!envp)
		return (ENV_PATH_ERR);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = -1;
	while (envp[++i])
	{
		path_slash = ft_strjoin(envp[i], "/");
		path_scmd = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(path_scmd, F_OK | X_OK) == 0)
		{
			free_matriz(envp);
			return (path_scmd);
		}
		free(path_scmd);
	}
	free_matriz(envp);
	return (0);
}

void	ft_exec(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*space_cmd;
	int		err;

	err = ft_caster(cmd);
	if (err == 1)
		return ;
	split_cmd = ft_split(cmd, SPACE);
	space_cmd = add_path(split_cmd[0], envp);
	if (execve(space_cmd, split_cmd, envp) < 0)
	{
		ft_putstr_fd("Pipex: cmd not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		free_matriz(split_cmd);
		exit(127);
	}
}

int	ft_caster(char *cmd)
{
	if (ft_strlen(cmd) == 0)
	{
		ft_putstr_fd("Pipex: argument is void", 2);
		return (1);
	}
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
//
// 	(void)argv;
// 	if (argc)
// 	{
// 		//find_path("path");
// 		ft_exec("ls  ", envp);
// 		printf("%s\n",envp);
// 		return (0);
// 	}
// }