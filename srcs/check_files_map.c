/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:29:54 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 09:14:39 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_files_map(int argc, char **argv)
{
	int	len_filename;

	if (argc != 2)
		error_msg("Error:\nimpossible d'ouvrir le fichier !");
	len_filename = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_filename - 4], ".cub", 4))
		error_msg("Error:\nle fichier ne contient pas l'extention .cub");
}
