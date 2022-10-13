/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/13 19:25:43 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main (int argc, char **argv)
{   
    t_image images;

    srand(time(0));
    check_files_map(argc, argv);
    init_map(&images.game, argv[1]);
    check_parameters_map(&images.game);
    init_var_player(&images.game);
    check_nb_player(&images.game);
    init_game(&images.game);
    print_map(&images.game);
    init_legend(&images.game, &images.legend);
    init_cube(&images.game, &images.cube);


    images.cube.sprite[0] = ft_strjoin("","./images_xpm/hand1.xpm");
    images.cube.sprite[1] = ft_strjoin("","./images_xpm/hand2.xpm");
    images.cube.nb_sprite = 0;

    images.cube.name_text[0] = ft_strjoin("","./images_xpm/text_star_16.xpm");
    images.cube.name_text[1] = ft_strjoin("","./images_xpm/text_star_14.xpm");
    images.cube.name_text[2] = ft_strjoin("","./images_xpm/text_star_20.xpm");
    images.cube.name_text[3] = ft_strjoin("","./images_xpm/text_star_19.xpm");

    images.cube.name_text[4] = ft_strjoin("","./images_xpm/text_star_24.xpm");
    images.cube.name_text[5] = ft_strjoin("","./images_xpm/text_star_23.xpm");
    
    images.cube.name_text[6] = ft_strjoin("","./images_xpm/BOOM_3.xpm");
    images.cube.name_text[7] = ft_strjoin("","./images_xpm/BOOM_4.xpm");
    images.cube.name_text[8] = ft_strjoin("","./images_xpm/wall_anim_1.xpm");
    images.cube.name_text[9] = ft_strjoin("","./images_xpm/wall_anim_2.xpm");


    ft_init_text(&images.cube); 
    printf("**********  textures OK *******************\n");
    mlx_string_put(images.cube.mlx_ptr, images.cube.win_ptr, 250, 340, 
        0x00FF00, "       GO");

  
   // mlx_mouse_hide();
    # ifdef __APPLE__
        mlx_mouse_move(images.game.win_ptr, (CUBE_X / 2), CUBE_Y );
    # endif

    mlx_loop_hook(images.game.mlx_ptr, *ft_input_2, &images);
  //  mlx_loop_hook(images.game.mlx_ptr, *reprint_pos, &images.game);//
    mlx_hook(images.game.win_ptr, 2, 1L<<0, *ft_input, &images);
    mlx_hook(images.game.win_ptr, 17, 1L << 17, ft_close, &images);
    mlx_hook(images.game.win_ptr, 6, 1, *move_test, &images);
  //  printf("***  test   ****\n");
    mlx_mouse_hook(images.game.win_ptr, *movements_mouse, &images);
  //  mlx_loop_hook(images.game.win_ptr, ft_input_2, &images);

   // mlx_hook(images.game.win_ptr, 6, 0, movements_mouse, &images);
    
    mlx_loop(images.game.mlx_ptr);
}