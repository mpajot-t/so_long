/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:33:27 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/02/07 10:59:17 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */

/* void	write_square(t_data *data, int width, int height, int x, int y)
{
	int nbr_pixels;
	int i;
	int line;
	int	j;

	nbr_pixels = width * height;
	i = 0;
	j = 0;
	line = 0;
	while (i < nbr_pixels)
	{
		if (line == width)
		{
			line = 0;
			j++;
		}
		my_mlx_pixel_put(data, x + line, y + j, 0x00FF0000);
		line++;
		i++;
	}
} */

int main(void)
{
	/* t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
    data->mlx_ptr = NULL;
    data->mlx_win = NULL;
    data->img = NULL;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "so_long");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, 
									&data->endian);
	write_square(data, 1920, 1080, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
    free(data); */
	t_data *data;
	char *path;

	path = "./sprites/golden_ball.png"
}