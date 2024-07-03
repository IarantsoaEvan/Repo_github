/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:03:47 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/08 10:03:51 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_ap(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_print_char(va_arg(ap, int));
	else if (c == 's')
		i += ft_print_str(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		i += ft_print_int(va_arg(ap, int));
	else if (c == 'u')
		i += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_print_hex(va_arg(ap, int), c);
	else if (c == 'p')
		i += ft_print_p(va_arg(ap, unsigned long long));
	else if (c == '%')
		i += ft_print_char('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		char_len;
	va_list	ap;

	if (format == NULL)
		return (0);
	char_len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			char_len += check_ap(*format, ap);
		}
		else
			char_len += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (char_len);
}
