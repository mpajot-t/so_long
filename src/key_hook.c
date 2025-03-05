/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:34:35 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/05 10:08:27 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	int new_y;
	int new_x;

	new_y = data->y;
	new_x = data->x;
	if (keycode == XK_w)
		new_y--;
	else if (keycode == XK_a)
		new_x--;
	else if (keycode == XK_s)
		new_y++;
	else if (keycode == XK_d)
		new_x++;
	else if (keycode == XK_Escape)
		free_all(data);
	if (data->map[new_y][new_x] != '1')
		update_position(data, new_y, new_x);
	return (0);
}