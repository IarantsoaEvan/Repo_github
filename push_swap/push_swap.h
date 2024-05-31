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

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct sst_node
{
	int	data;
	int	curr_pos;
	int	above_med;
	int	push_value;
	int	chp;
	struct sst_node		*target;
	struct sst_node		*next;
	struct sst_node		*prev;
}	t_node;

t_node	*whos_last(t_node *root);
t_node *find_max(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*chp_is_one(t_node *stack);
void	add_nd(t_node **stack, int nbr);
void	sort_three(t_node **lst);
void	prep_for_push(t_node **stack, t_node *top, char stack_name);
void	sort_1(t_node **a, t_node **b);
long	ft_atl(const char *str);
char	**ft_join_av(char **av);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	curr_position(t_node *stack);
void	see_cheapest(t_node *stack);
void	inits_a(t_node *a, t_node *b);
void	inits_b(t_node *a, t_node *b);
void	rotate_square(t_node **a, t_node **b, t_node *chp);
void	rr_square (t_node **a, t_node **b, t_node *chp);
int		set_up(t_node **a, char **av);
int		ft_av_isdigit(char **av);
int		dupli_same(t_node *a, int nbr);
int		bool_error(int error, int b, char **av);
int		ft_is_space(char *str);
int		ft_is_sorted(t_node *a);
int		stack_len(t_node *a);
int		first_check(char **av);

#endif
