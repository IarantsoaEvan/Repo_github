/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:35 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/08 11:11:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_int(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(int nbr, char t);
int	ft_print_p(unsigned long ptr);

#endif
