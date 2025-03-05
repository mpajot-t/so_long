/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:14:32 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/05 10:08:27 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	finish(t_data *data)
{
	ft_printf("Bravo, tu as fini le jeu\n");
	free_all(data);
	exit(0);
}

static	void	update_img(t_data *data, int new_y, int new_x)
{
	if (data->map[data->y][data->x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_floor, 
		(data->x * 96), (data->y * 96));
	}
	else 
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_exit, 
		(data->x * 96), (data->y * 96));
	if (data->map[new_y][new_x] == 'C')
	{
		data->cur_balls++;
		data->map[new_y][new_x] = '0';
		if (data->cur_balls == data->nb_balls)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_exit2, 
			(data->exit_x * 96), (data->exit_y * 96));
		}
		//ft_printf("Nb de balls :%d\n", data->cur_balls);
	}
	data->steps++;
	ft_printf("Steps : %d\n", data->steps);
}

void	update_position(t_data *data, int new_y, int new_x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_player, 
	(new_x * 96), (new_y * 96));
	if (data->y != new_y || data->x != new_x)
		update_img(data, new_y, new_x);
	data->y = new_y;
	data->x = new_x;
	if (data->cur_balls == data->nb_balls && data->map[new_y][new_x] == 'E')
		finish(data);
}
