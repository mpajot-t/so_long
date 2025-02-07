/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:25:55 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/26 10:17:30 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i++;
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_unsintlen(unsigned int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
