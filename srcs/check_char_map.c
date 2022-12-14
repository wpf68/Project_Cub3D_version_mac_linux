/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:05:24 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 14:18:04 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map.tab[++i])
	{
		while (game->map.tab[i][++j])
		{
			if (find_char(game->map.tab[i][j], " \t01NSEW") == 0)
				return (0);
		}
		j = -1;
	}
	return (1);
}
