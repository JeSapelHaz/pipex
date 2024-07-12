/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:17:34 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/12 16:27:04 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	// pid_t pid;;
	// int pipe_id[2];

	// (void)av;
	// check_args(ac);
	// pid = fork();
	// if (pipe(pipe_id) == -1)
	// 	ft_error("Erreur dans le pipe");
	// if (pid == -1)
	// 	ft_error("Erreur dans le fork");
	// if (pid == 0)
	// 	printf("Je suis l'enfant\n");
	// else
	// {
	// 	wait(NULL);
	// 	printf("Je suis le parent\n");
	// }
	
	(void) ac;
	(void) av;
	int fd[2];
	pid_t pid;
	char buffer[13];
 
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}