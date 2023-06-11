/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:49:52 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/10 11:21:51 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack	t_stack;
struct s_stack
{
	int		num;
	int		pos;
	t_stack	*next;
};

t_stack	*get_tail(t_stack **stack);
t_stack	*new_elem(int value);
t_stack	*add_elem(t_stack **stack, int value);
int		is_ordered(t_stack **stack);
t_stack	*valid_arr(int argc, char **argv, t_stack **stack);
int		atoiable(char *num);
int		not_found(t_stack **stack, int value);
int		splitable(t_stack **stack, char *num);
int		no_repeat(char **splits);
void	clear_stack(t_stack **stack);
void	s_ab(t_stack **stack, char v);
void	r_ab(t_stack **stack, char v);
void	rr_ab(t_stack **stack, char v);
void	p_ab(t_stack **orig, t_stack **dest, char v);
void	sort3_elem(t_stack **stack, char v);
int		midpoint(t_stack **stack);
int		stack_len(t_stack **stack);
int		find_bigger(t_stack **stack);
int		sml_num(t_stack **stack);
int		sml_to_top(t_stack **stack, char v);
void	sort5_elem(t_stack **a, char v);
void	sortall_elem(t_stack **a);
t_stack	*new_aux(t_stack **stack, t_stack **aux, int lim);
void	radix_sort(t_stack **a, t_stack **b, int size, char v);
void	print_list(t_stack **stack);
char	rev_v(char v);
void	sort_pos(t_stack **a, t_stack **aux);

#endif
