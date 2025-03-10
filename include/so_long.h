/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:35:48 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/07 10:35:26 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include "../Libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"

typedef struct img_s
{
	char	*floor;
	char	*wall;
	char	*exit;
	char	*exit2;
	char	*player;
	char	*collect;
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_exit2;
	void	*img_player;
	void	*img_collect;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		nb_balls;
	int		cur_balls;
	int		steps;
	char	**map;
	char	**map_copy;
	t_img	*img;
}	t_data;

typedef struct s_map_check
{
	int	exit;
	int	item;
	int	start;
}	t_map_check;

void	get_map(char *path, t_data *data);
int		ber_check(char *map_name);
int		map_check(t_data *data);
void	errors_message(int index);
int		get_map_line_width(t_data *data);
int		get_map_height(t_data *data);
int		is_map_valid(t_data *data, int width, int height);
t_img	*initialize_img(t_img *img);
t_data	*initialize_data(t_img *img, char *argv);
void	generate_map(t_data *data);
int		key_hook(int keycode, t_data *data);
void	find_player_and_exit(t_data *data);
void	get_balls(t_data *data);
void	update_position(t_data *data, int new_y, int new_x);
void	free_all(t_data *data);
#endif