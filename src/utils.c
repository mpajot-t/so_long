/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:35:20 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/10 09:30:29 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errors_message(int index)
{
	ft_printf("Error.\n");
	if (index == 0)
		ft_printf("Aucun fichier de map inclus.\n");
	else if (index == 1)
		ft_printf("La map n'est pas rectangulaire.\n");
	else if (index == 2)
		ft_printf("Erreur dans la composition de la map.\n");
	else if (index == 3)
		ft_printf("Caractère non autorisé.\n");
	else if (index == 4)
		ft_printf("La map est impossible à finir.\n");
	else if (index == 5)
		ft_printf("La map n'est pas entièrement entourée de murs.\n");
	else if (index == 6)
		ft_printf("L'extension de fichier est incorrecte.\n");
	else if (index == 7)
		ft_printf("Fichier vide.\n");
	else if (index == 8)
		ft_printf("Fichier inexistant.\n");
}

int	get_map_line_width(t_data *data)
{
	int	i;
	int	line_width;

	i = 0;
	line_width = 0;
	while (data->map[i][line_width] != '\0')
		line_width++;
	return (line_width);
}

int	get_map_height(t_data *data)
{
	int	height;
	int	i;
	int	j;

	height = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
			j++;
		i++;
		height++;
	}
	return (height);
}

void	find_player_and_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
			}
			else if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	get_balls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'C')
				data->nb_balls++;
			x++;
		}
		y++;
	}
}
