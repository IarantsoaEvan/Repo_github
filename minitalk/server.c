/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:10:13 by irabesan          #+#    #+#             */
/*   Updated: 2024/06/05 11:10:15 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		result = nb * ft_recursive_power(nb, power - 1);
		return (result);
	}
}

char	*assemble_message(const char *s1, const char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	str[j++] = c;
	str[j] = 0;
	free((void *)(s1));
	return (str);
}

void	sig_handler(int signum)
{
	static int	count;
	static int	result;
	static char	*f_message;

	if (!f_message)
		f_message = ft_strdup("");
	if (signum == SIGUSR2)
		result = result + 0;
	else if (signum == SIGUSR1)
		result = result + (1 * ft_recursive_power(2, 7 - count));
	count++;
	if (count == 8)
	{
		f_message = assemble_message(f_message, result);
		if (result == '\0')
		{
			ft_printf("%s\n", f_message);
			free(f_message);
			f_message = NULL;
		}
		count = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("===========START===========\n");
	ft_printf("Server's PID: %d\n", getpid());
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		usleep(50);
	}
}
