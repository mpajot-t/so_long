/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:34:38 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/05 10:08:27 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img(t_data *data)
{
	if (data->img)
	{
		if (data->img->img_floor)
			mlx_destroy_image(data->mlx, data->img->img_floor);
		if (data->img->img_collect)
			mlx_destroy_image(data->mlx, data->img->img_collect);
		if (data->img->img_player)
			mlx_destroy_image(data->mlx, data->img->img_player);
		if (data->img->img_wall)
			mlx_destroy_image(data->mlx, data->img->img_wall);
		if (data->img->img_exit)
			mlx_destroy_image(data->mlx, data->img->img_exit);
		if (data->img->img_exit2)
			mlx_destroy_image(data->mlx, data->img->img_exit2);
		free(data->img);
	}
}
void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_img(data);
	if (data->map)
	{
		int i = 0;
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(0);
}
