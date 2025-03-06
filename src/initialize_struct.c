/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:26:34 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/06 10:19:16 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*initialize_data(t_img *img, char *argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = img;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->x = 0;
	data->y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->cur_balls = 0;
	data->nb_balls = 0;
	data->steps = 0;
	get_map(argv, data);
	data->map_copy = NULL;
	data->height = get_map_line_width(data) * 96;
	data->width = get_map_height(data) * 96;
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

t_img	*initialize_img(t_img *img)
{
	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->collect = NULL;
	img->wall = NULL;
	img->exit = NULL;
	img->exit2 = NULL;
	img->floor = NULL;
	img->player = NULL;
	img->height = 0;
	img->width = 0;
	img->img_collect = NULL;
	img->img_exit = NULL;
	img->img_exit2 = NULL;
	img->img_floor = NULL;
	img->img_player = NULL;
	img->img_wall = NULL;
	return (img);
}
