/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:57:53 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/29 11:08:29 by irabesan         ###   ########.fr       */
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

# endif
