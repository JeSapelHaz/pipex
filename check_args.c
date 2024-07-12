/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:12:47 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/10 13:18:17 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_args(int ac)
{
	if (ac < 5)
		ft_error("Pas assez d'arguments, applique toi chef");
}