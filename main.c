/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:17:34 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/27 18:07:41 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

(void) av;
(void) env;
	check_args(ac);
	if (pipe(fd) == -1)
		ft_error("Error dans le pipe\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error dans le fork");
	if (pid == 0)
		// child_process(av, fd, env);
	waitpid(pid, NULL, 0);
	// parent_process(av, fd, env);
}
