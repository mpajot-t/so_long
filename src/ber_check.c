/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:35:33 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/10 09:30:55 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		if (s1[i] < s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ber_check(char *map_name)
{
	int	len;
	int fd;

	len = ft_strlen(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (errors_message(8), 1);
	if (len < 4)
		return (errors_message(6), 1);
	if (ft_strcmp(&map_name[len - 4], ".ber") == 0)
		return (0);
	close(fd);
	return (errors_message(6), 1);
}
