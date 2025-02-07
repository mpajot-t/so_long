/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:23:04 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/26 10:20:37 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	print_nb(int n)
{
	char	nbr[12];
	int		i;
	int		len;
	int		orig_len;

	i = 0;
	if (n < 0)
	{
		nbr[i++] = '-';
		n = -n;
	}
	len = ft_intlen(n);
	orig_len = len + i;
	while (n > 0)
	{
		nbr[i + len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	write (1, nbr, orig_len);
	return (orig_len);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	return (print_nb(n));
}

int	ft_putunsnbr(unsigned int n)
{
	char	nbr[12];
	int		len;
	int		orig_len;

	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	len = ft_unsintlen(n);
	orig_len = len;
	while (len > 0)
	{
		nbr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	write (1, nbr, orig_len);
	return (orig_len);
}
