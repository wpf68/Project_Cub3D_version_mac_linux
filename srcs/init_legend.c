#include "../includes/cub3d.h"

void    init_legend(t_game *game, t_game *legend)
{
  //  int y;

    legend->mlx_ptr = game->mlx_ptr;
    legend->win_ptr = game->win_ptr;
    legend->map.lines = game->map.lines;
    legend->map.columns = game->map.columns;
    legend->map.move = 0;
    legend->apos_game = &(game->map.p.apos);

    printf("apos legende = %f  --   apos game = %f\n", *legend->apos_game, game->map.p.apos);  // test

 //   y = (legend->map.lines *10) + BORDER_Y;
 //   if (y < HEIGHT_MINI)
 //       y = HEIGHT_MINI;
    legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, LEGENDE_X, LEGENDE_Y); 
    legend->img.addr = mlx_get_data_addr(legend->img.mlx_img, &legend->img.bpp,
			&legend->img.line_len, &legend->img.endian); //

   // draw_square(legend, 30, 40, 20, encode_rgb(0, 255,0));
    int			wi;
    int			he;
    legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/Cube3D_1b.xpm", &wi, &he);
    mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, IMAGE_X - 300, 0); // put image finie

   // mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 15, 0xFFFFFF, "Cub3D");
}

void    draw_circle_bis(t_game *image, int x, int y, int r, int color)
{
    double  cos_x;
    double  sin_y;
    double  i;

    i = 0;
    while (i < 2 * 3.141592)
    {
        cos_x = cos(i) * (r);
        sin_y = sin(i) * (r);
        img_pix_put(image, x + cos_x, y + sin_y, color);
        i += 0.2;
    }


}



void    draw_circle(t_game *image, int x, int y, int r, int color)
{

    int  i;

    i = r - 3;

    while (i < (r + 4))
    {
        draw_circle_bis(image, x, y, i, color);
        i++;
    }

        // clacul de l'orientation du joueur sur le cercle
    image->r.dir_x = x - cos(*image->apos_game) * r;
    image->r.dir_y = y - sin(*image->apos_game) * r;

    i = 0;
    while (i < 3)
    {
        draw_circle_bis(image, image->r.dir_x, image->r.dir_y, i, 0x0050D317);
        i++;
    }
    while (i < 5)
    {
        draw_circle_bis(image, image->r.dir_x, image->r.dir_y, i, 0x002F7E0D);
        i++;
    }
/*
    i = 0;
    while (i < 2 * 3.141592)
    {
        cos_x = cos(i) * (r + 3);
        sin_y = sin(i) * (r + 3);
        img_pix_put(image, x + cos_x, y + sin_y, color);
        i += 0.06;
    }

    i = 0;
    while (i < 2 * 3.141592)
    {
        cos_x = cos(i) * (r - 3);
        sin_y = sin(i) * (r - 3);
        img_pix_put(image, x + cos_x, y + sin_y, color);
        i += 0.06;
    }
    // clacul de l'orientation du joueur sur le cercle
    image->r.dir_x = x - cos(*image->apos_game) * r;
    image->r.dir_y = y - sin(*image->apos_game) * r;

    i = 0;
    while (i < 2 * 3.141592)
    {
        cos_x = cos(i) * 4;
        sin_y = sin(i) * 4;
        img_pix_put(image, image->r.dir_x + cos_x, image->r.dir_y + sin_y, SOUTH_COLOR);
        i += 0.2;
    }
    */
}

int    anim_legend(t_game *legend)
{
    static  int cpt_anime;
  //  int r = rand() % 255;
   // int g = rand() % 255;
    //int b = rand() % 255;
   // int move;
    int y;
    char    *itoa_angle;
    char    *temp;

   

    //printf("cpt_anime =  %d\n", cpt_anime); // ok
    cpt_anime++;
    if (cpt_anime % SPEED_MOVIE == 1)
    {
        legend->map.move += 1;
   //     move = legend->map.move % 8;

        mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);//

        y = (legend->map.lines *10) + BORDER_Y;
        if (y < HEIGHT_MINI)
            y = HEIGHT_MINI;
       // legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, BORDER_X, y); 
        legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 121, 113); 

    int			wi;
    int			he;
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/Cube3D_2b.xpm", &wi, &he);


        legend->img.addr = mlx_get_data_addr(legend->img.mlx_img, &legend->img.bpp,
                &legend->img.line_len, &legend->img.endian); //
        draw_circle(legend, 60, 56, 48, 0x00DF9D00);

     //  draw_circle(legend, legend->r.dir_x, legend->r.dir_y, 4, SOUTH_COLOR);



/*
        // usleep(SPEED_MOVIE); // boock le prg rmplacé par cpt_anime
        draw_square(legend, 100, 15, 8, encode_rgb(255, 0, 0));
        draw_square(legend, 115, 15, 8, encode_rgb(0, 255, 0));
        draw_square(legend, 130, 15, 8, encode_rgb(0, 0, 255));
        draw_square(legend, 145, 15, 8, WEST_COLOR);
*/
        //  ----  Radar
     //   draw_circle(legend, 148, 260, 105, WEST_COLOR);
      //  draw_circle(legend, 148, 110, 105, WEST_COLOR);
        

        //draw_circle_player();

        
       
       
        
      //  mlx_put_image_to_window(so->mlx, so->wim, so->cr, x, y);


   //     mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, (legend->map.columns * 10) + 5, 0); // put image finie
     //   mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, (legend->map.columns * 10) + 100, 205); // put image finie
        mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, IMAGE_X - 300 + 90, 204); // put image finie

    /*
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 110, 0xFF0000, "NORTH");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 125, 0x00FF00, "SOUTH");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 140, 0x0000FF, "EAST");
        */

        int angle = (*legend->apos_game) * 180 / 3.14;
        if (angle < 0)
            angle = angle * (-1) + 180;
        angle %= 360;

        itoa_angle = ft_itoa(angle);
        if (ft_strlen(itoa_angle) < 3)
        {
            temp = itoa_angle;
            itoa_angle = ft_strjoin("0", temp);
            free(temp);
        }
        if (ft_strlen(itoa_angle) < 3)
        {
            temp = itoa_angle;
            itoa_angle = ft_strjoin("0", temp);
            free(temp);
        }

      //  mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + DEGREE_X1, DEGREE_Y1, WEST_COLOR, "degree angle");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, IMAGE_X - 300 - 5 + DEGREE_X2, DEGREE_Y2, SOUTH_COLOR, itoa_angle);
        free(itoa_angle);
/*
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 180, 0xFFFFFF, "    W / UP");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 195, 0xFFFFFF, "      |");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 210, 0xFFFFFF, " A  --+--  D");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 225, 0xFFFFFF, "      | ");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 40, 240, 0xFFFFFF, "   S / DOWN");

        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 23, 270, 0xFFFFFF, "LEFT <- O-O -> RIGHT");

        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 27, 13 + move, encode_rgb(r, g, b), "***");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 52, 15, 0xFFFFFF, "Cub3D");
        mlx_string_put(legend->mlx_ptr, legend->win_ptr, (legend->map.columns *10) + 87, 13 + move, encode_rgb(r, g, b), "***");

        */

    }

    return (0);
}