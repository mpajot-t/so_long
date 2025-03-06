/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:22:39 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/06 10:23:53 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_xpm_sprites(t_data *data)
{
	data->img->img_floor = mlx_xpm_file_to_image(data->mlx, data->img->floor,
			&data->img->width, &data->img->height);
	data->img->img_collect = mlx_xpm_file_to_image(data->mlx,
			data->img->collect, &data->img->width, &data->img->height);
	data->img->img_exit = mlx_xpm_file_to_image(data->mlx, data->img->exit,
			&data->img->width, &data->img->height);
	data->img->img_exit2 = mlx_xpm_file_to_image(data->mlx, data->img->exit2,
			&data->img->width, &data->img->height);
	data->img->img_player = mlx_xpm_file_to_image(data->mlx, data->img->player,
			&data->img->width, &data->img->height);
	data->img->img_wall = mlx_xpm_file_to_image(data->mlx, data->img->wall,
			&data->img->width, &data->img->height);
}

static void	put_img_to_win(t_data *data, void *img)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img,
		data->x, data->y);
	data->x += 96;
}

static void	generate_sprites(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	get_xpm_sprites(data);
	while (data->map[++i])
	{
		j = 0;
		data->x = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				put_img_to_win(data, data->img->img_wall);
			else if (data->map[i][j] == '0')
				put_img_to_win(data, data->img->img_floor);
			else if (data->map[i][j] == 'E')
				put_img_to_win(data, data->img->img_exit);
			else if (data->map[i][j] == 'P')
				put_img_to_win(data, data->img->img_player);
			else if (data->map[i][j] == 'C')
				put_img_to_win(data, data->img->img_collect);
			j++;
		}
		data->y += 96;
	}
}

void	generate_map(t_data *data)
{
	data->img->collect = "sprites/collect.xpm";
	data->img->wall = "sprites/wall_center.xpm";
	data->img->exit = "sprites/exit.xpm";
	data->img->exit2 = "sprites/exit2.xpm";
	data->img->floor = "sprites/floor6.xpm";
	data->img->player = "sprites/player.xpm";
	data->img->height = 96;
	data->img->width = 96;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->height,
			data->width, "so_long");
	get_balls(data);
	generate_sprites(data);
}
