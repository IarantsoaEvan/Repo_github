/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fizzbuzz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:19:02 by irabesan          #+#    #+#             */
/*   Updated: 2024/06/05 11:19:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_nbr(int nbr)
{
	char 	*str = "0123456789";
	if (nbr > 9)
		write_nbr(nbr / 10);
	write(1, &str[nbr % 10], 1);
}
int main()
{
	int i = 1;
	
	while (i <= 100)
	{
		if ((i % 15) == 0)
			write(1, "fizzbuzz", 8);
		else if ((i % 3) == 0)
			write(1, "fizz", 4);
		else if ((i % 5) == 0)
			write(1, "buzz", 4);
		else
			write_nbr(i);
		i++;
		write(1, "\n", 1);
	}
}
