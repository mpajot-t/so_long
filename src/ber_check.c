/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:35:33 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/06 09:54:44 by mpajot-t         ###   ########.fr       */
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

	len = ft_strlen(map_name);
	if (len < 4)
		return (0);
	if (ft_strcmp(&map_name[len - 4], ".ber") == 0)
		return (1);
	return (0);
}
