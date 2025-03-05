/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:33:29 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/05 10:08:27 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_height_path(char *path)
{
	int fd;
	int height;
	char *line;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	fill_map(t_data *data, char *path)
{
	char *line;
	int line_width;
	int index;
	int fd;

	index = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(data->map);
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_width = ft_strlen(line);
		data->map[index] = line;
		if (data->map[index][line_width - 1] == '\n')
			data->map[index][line_width - 1] = '\0';
		index++;
		line = get_next_line(fd);
	}
	data->map[index] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map(char *path, t_data *data)
{
	int height;

	height = get_map_height_path(path);
	if (height == -1)
		return ;
	data->map = malloc((height + 1) * sizeof(char *));
	if (!data->map)
		return ;
	fill_map(data, path);
}
