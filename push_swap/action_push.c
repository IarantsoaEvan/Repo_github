 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:07:32 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/02 17:07:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(ts_node **dest, ts_node **src)
{
	ts_node	*nd;

	if (*src == NULL)
		return ;
	nd = *src;
	*src = (*src)->next;
}
