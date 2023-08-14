/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:10:06 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/08 11:54:43 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// include libft
# include "libft/libft.h"
# include <ctype.h>
# include <fcntl.h> // to open file
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h> // perror
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <strings.h>
# include <sys/wait.h> // wait
# include <unistd.h>   // Execeve, fork , dup, dump2, write, pipe

// Constantes o Macros
# define STDIN 0  // indice del extremo de lectura del pipe
# define STDOUT 1 // indice del extremo de  escritura del pipe
# define STDERR 2

# define EXIT_CMD_ERR 127 // el 127 significa que ha habido un error al ejecutar

# define MEM_ERR "Error en la memmoria"
# define CMD_ERR "Invalid Command"
# define FORK_ERR "Fork problem"
# define PIPE_ERR "Pipe problem"
# define ENV_PATH_ERR "Env path get problem"
# define OPEN_FILE_ERR "No find file or directory"
# define SPACE ' '

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	int		status;
	char	**env_path;
	char	**cmd_path;
	char	*cmd;
	char	*path;
	int		fd_in_file;
	int		fd_out_file;
	pid_t	id_;
	pid_t	pid2;
	int		fd_pipe[2];
}			t_pipex;

void		ft_error(char *str);
void		free_arr(char **argv);
void		free_matriz(char **matriz);

char		**find_path(char **envp);
char		*add_path(char *cmd, char **env);
void		ft_exec(char *cmd, char **envp);
int			ft_open(char *file, int std);
int			ft_caster(char *cmd);

void		first_process_child(int *fd, char **argv, char **env);
void		secund_process_child(int *fd, char **argv, char **env);
void		pipex(char **cmd, char **envp);
int			main(int argc, char **argv, char **env);

#endif
