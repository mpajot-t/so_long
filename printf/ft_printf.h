/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:32:25 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/26 10:17:56 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LHEXA "0123456789abcdef"
# define UHEXA "0123456789ABCDEF"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	check_format(const char format, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_hexaformat(void	*ptr);
int	ft_putnbr(int n);
int	ft_intlen(int a);
int	ft_unsintlen(unsigned int a);
int	ft_putunsnbr(unsigned int n);
int	ft_hexadecimal(unsigned int n, char c);
int	ft_putpercent(void);
int	ft_puthex_lower(unsigned long nbr);
int	ft_puthex_upper(unsigned long nbr);
#endif