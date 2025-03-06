/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:01:18 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/06 10:25:58 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_chars(t_data *data, t_map_check check)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != 'C' && data->map[i][j] != 'E' &&
				data->map[i][j] != 'P'
				&& data->map[i][j] != '0' && data->map[i][j] != '1')
				return (errors_message(3), 0);
			if (data->map[i][j] == 'C')
				check.item++;
			else if (data->map[i][j] == 'E')
				check.exit++;
			else if (data->map[i][j] == 'P')
				check.start++;
			j++;
		}
	}
	if (check.item < 1 || check.exit != 1 || check.start != 1)
		return (errors_message(2), 0);
	return (1);
}

static int	check_walls(t_data *data, int height, int width)
{
	int	i;

	i = -1;
	while (data->map[0][++i] != '\0')
	{
		if (data->map[0][i] != '1')
			return (errors_message(5), 0);
	}
	i = -1;
	while (++i < height - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][width - 1] != '1')
			return (errors_message(5), 0);
	}
	i = -1;
	while (data->map[height - 1][++i] != '\0')
	{
		if (data->map[height - 1][i] != '1')
			return (errors_message(5), 0);
	}
	return (1);
}

static int	line_check(t_data *data)
{
	int	line_width;
	int	previous_line;
	int	i;

	i = 0;
	while (data->map[i])
	{
		line_width = 0;
		while (data->map[i][line_width] != '\0')
			line_width++;
		if (i >= 1 && line_width != previous_line)
			return (errors_message(1), 0);
		previous_line = line_width;
		i++;
	}
	return (1);
}

int	map_check(t_data *data)
{
	t_map_check	check;
	int			width;
	int			height;

	check.item = 0;
	check.start = 0;
	check.exit = 0;
	width = get_map_line_width(data);
	height = get_map_height(data);
	if (!data->map)
		return (0);
	if (!count_chars(data, check))
		return (0);
	if (!line_check(data))
		return (0);
	if (!check_walls(data, height, width))
		return (0);
	if (!is_map_valid(data, width, height))
		return (errors_message(4), 0);
	return (1);
}
