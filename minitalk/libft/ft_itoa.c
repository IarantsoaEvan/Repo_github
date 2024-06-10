/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:48:43 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/26 07:48:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_nbr(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*is_0(char *str)
{
	*str = '0';
	*(str + 1) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		x;
	long int	num;

	num = n;
	x = len_nbr(n);
	if (n < 0)
	{
		num *= -1;
		x++;
	}
	str_num = (char *)malloc((x + 1) * sizeof(char));
	if (n == 0)
		return (is_0(str_num));
	if (!str_num)
		return (NULL);
	*(str_num + x) = '\0';
	while (x--)
	{
		*(str_num + x) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}

/*int main ()
{
	printf("%s", ft_itoa(-12123123));
	return (0);
}*/
