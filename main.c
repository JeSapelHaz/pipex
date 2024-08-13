/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:17:34 by hbutt             #+#    #+#             */
/*   Updated: 2024/08/12 17:25:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	check_args(ac);
	if (pipe(pipe_fd) == -1)
		ft_error("Error dans le pipe\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error dans le fork");
	if (pid == 0)
		child_process(av[1], av[2], pipe_fd, env);
	waitpid(pid, NULL, 0);
	parent_process(av[4], av[3], pipe_fd, env);
}
