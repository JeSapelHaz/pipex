/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:12:47 by hbutt             #+#    #+#             */
/*   Updated: 2024/08/12 17:24:31 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac)
{
	if (ac < 5)
		ft_error("Pas assez d'arguments, applique toi chef");
	if (ac > 5)
		ft_error("Trop d'arguments mon gourmand");
}
