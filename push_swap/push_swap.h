/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:57:53 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/02 15:49:56 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	sst_node
{
	int	data;
	int	idx;
	int	push_value;
	int	min_cost;
	struct sst_node	*target;
	struct sst_node	*next;
	struct sst_node	*prev;
}ts_node;

ts_node	*whos_last(ts_node *root);
void	add_nd(ts_node *stack, int nbr);
int	set_up(ts_node **a, char **av);
long	ft_atl(const char *str);
int	ft_isdigit(char **av);
int	dupli_same(ts_node *a, int nbr);
char	**ft_split(char const *s, char c);
int	bool_error(int error, int b, char **av);



# endif
