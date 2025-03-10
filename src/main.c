/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:33:27 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/10 09:29:58 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_win(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_img	*img;

	img = NULL;
	if (argc != 2)
		return (errors_message(0), 1);
	if (ber_check(argv[1]))
		return (1);
	img = initialize_img(img);
	data = initialize_data(img, argv[1]);
	if (map_check(data) == 0)
		return (free_all(data), 0);
	generate_map(data);
	find_player_and_exit(data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
