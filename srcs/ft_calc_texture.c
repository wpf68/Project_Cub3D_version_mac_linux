/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:54:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 15:41:16 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_calc_texture(double x_map, int i, t_image *images, int face)
{
    double  x;
    char    *pixel;
    int     x_text;
    int     y_text;
    int     height;

    height = images->cube.r.drawEnd - images->cube.r.drawStart;
    x = x_map / (1.0 * (images->game.rapport_player)) - (int)(x_map / 
      (1.0 * (images->game.rapport_player)));
    x_text = (x * images->cube.img_text[face].size.x); 
    y_text = (((i * 1.0) / height) * images->cube.img_text[face].size.y); 
    pixel = images->cube.img_text[face].addr + (y_text * 
      images->cube.img_text[face].line_len + x_text * 
      (images->cube.img_text[face].bpp / 8));

    return (*(unsigned int *) pixel);
}