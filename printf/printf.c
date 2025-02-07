/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:32:22 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/26 10:11:01 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (format == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len = ft_hexaformat(va_arg(args, void *));
	else if (format == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_putunsnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len = ft_puthex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		len = ft_puthex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		len = ft_putpercent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check_format(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>
int main(void)
{
    int len;

    len = ft_printf("Hex (uppercase) of 0: %X\n", 0);
    printf("Length: %d\n", len);
	
    len = ft_printf("Hex (uppercase) of 255: %X\n", 255);
    printf("Length: %d\n", len);

    len = ft_printf("Hex (uppercase) of 4294967295: %X\n", 4294967295U);
    printf("Length: %d\n", len);

    len = ft_printf("Hex (uppercase) of 123456: %X\n", 123456);
    printf("Length: %d\n", len);

    len = ft_printf("Mix of formats: %X %X %X\n", 15, 240, 4096);
    printf("Length: %d\n", len);

	len = ft_printf("Nombre 2568 = %d\n", 2568);
	printf("Length: %d\n", len);

	len = ft_printf("Nombre -25689 = %d\n", -25689);
	printf("Length: %d\n", len);

	len = ft_printf("Nombre 4568 = %i\n", 4568);
	printf("Length: %d\n", len);

	len = ft_printf("Nombre -22 = %i\n", -22);
	printf("Length: %d\n", len);

	len = ft_printf("Nombre 822 = %u\n", -822);
	printf("Length: %d\n", len);
	
	len = ft_printf("Nombre 0 = %u\n", 0);
	printf("Length: %d\n", len);
	
    return 0;
} */