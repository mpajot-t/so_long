/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:26:57 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/05 10:08:27 by mpajot-t         ###   ########.fr       */
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

int	is_map_valid(t_data *data, int width, int height)
{
	char	**map_copy;
	int		x, y;
	int		valid = 1;

	y = 0;
	map_copy = copy_map(data);
	if (!map_copy)
		return (0);
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
	flood_fill(map_copy, x, y);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (data->map[y][x] == 'C' || data->map[y][x] == 'E') 
			{
				if (map_copy[y][x] != 'F')
					valid = 0;
			}
			x++;
		}
		free(map_copy[y]);
		y++;
	}
	free(map_copy);
	return (valid);
}
