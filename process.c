/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:15:12 by hbutt             #+#    #+#             */
/*   Updated: 2024/08/13 14:03:48 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env, int i)
{
	char	**cmd_gui;
	char	*path;

	cmd_gui = ft_split(cmd, ' ');
	path = get_path(cmd_gui[0], env);
	if (execve(path, cmd_gui, env) == -1)
	{
		ft_free_tab(cmd_gui);
		free(path);
		if (i == 1)
			ft_error_2("La commande 1 est cassée");
		if (i == 2)
			ft_error_2("La commande 2 est cassée");
	}
}

void	child_process(char *filein, char *cmd1, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(filein, O_RDONLY, 0777);
	if (fd == -1)
		ft_error("Ouverture de fichier d'entrée échouée");
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	exec(cmd1, env, 1);
}

void	parent_process(char *fileout, char *cmd2, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_error("Ouverture de fichier de sortie échouée");
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	exec(cmd2, env, 2);
}
