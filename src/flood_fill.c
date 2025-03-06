/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:26:57 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/06 10:07:35 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;
	int		height;

	height = get_map_height(data);
	copy = malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	find_player(t_data *data, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (data->map[y][x] == 'P')
				break ;
			x++;
		}
		if (data->map[y][x] == 'P')
			break ;
		y++;
	}
	flood_fill(data->map_copy, x, y);
}

int	is_map_valid(t_data *data, int width, int height)
{
	int		x;
	int		y;
	int		valid;

	y = -1;
	valid = 1;
	data->map_copy = copy_map(data);
	if (!data->map_copy)
		return (0);
	find_player(data, height, width);
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (data->map[y][x] == 'C' || data->map[y][x] == 'E')
			{
				if (data->map_copy[y][x] != 'F')
					valid = 0;
			}
		}
		free(data->map_copy[y]);
	}
	free(data->map_copy);
	return (valid);
}
