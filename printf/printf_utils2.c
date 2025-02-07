/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:22:50 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/26 09:19:44 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_hexaformat(void	*ptr)
{
	unsigned long	nbr;
	int				len;

	len = 0;
	nbr = (unsigned long)ptr;
	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	len += 2;
	return (len += ft_puthex_lower(nbr));
}

int	ft_puthex_lower(unsigned long nbr)
{
	char	hex_digits[16];
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		hex_digits[i] = LHEXA[nbr % 16];
		nbr = nbr / 16;
		len++;
		i++;
	}
	while (i-- > 0)
		write(1, &hex_digits[i], 1);
	return (len);
}

int	ft_puthex_upper(unsigned long nbr)
{
	char	hex_digits[16];
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		hex_digits[i] = UHEXA[nbr % 16];
		nbr = nbr / 16;
		len++;
		i++;
	}
	while (i-- > 0)
		write(1, &hex_digits[i], 1);
	return (len);
}

int	ft_putpercent(void)
{
	write (1, "%", 1);
	return (1);
}
