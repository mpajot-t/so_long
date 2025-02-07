/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:35:48 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/02/06 10:59:45 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# include "./Libft/libft.h"
# include "./printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

typedef struct	img_s {
	void	*floor;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collect;
	int		width;
	int		height;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}	t_data;

#endif