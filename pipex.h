/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:58:16 by hbutt             #+#    #+#             */
/*   Updated: 2024/08/08 15:43:42 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* Check args */
void	check_args(int ac);
char	*ft_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);

/* Utils */
void	ft_error(char *msg);
void	ft_error_2(char *msg);
void	ft_free_tab(char **tab);
int		ft_strcmp(char *s1, char *s2);
int		open_file(char *file, int in_or_out);

/* Process */
void	exec_process(char *cmd, char *env);
void	parent_process(char *fileout, char *cmd2, int *p_fd, char **env);
void	child_process(char *filein, char *cmd1, int *p_fd, char **env);

#endif