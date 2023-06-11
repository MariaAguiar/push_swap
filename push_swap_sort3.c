/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarida <margarida@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:56 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/06 22:20:51 by margarida        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

void	s_ab(t_stack **stack, char v)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!first || !(first->next))
		return ;
	second = first->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
	if (v != ' ')
		ft_printf("s%c\n", v);
}

void	r_ab(t_stack **stack, char v)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	if (!head || !head->next)
		return ;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	*stack = head->next;
	head->next = NULL;
	if (v != ' ')
		ft_printf("r%c\n", v);
}

void	rr_ab(t_stack **stack, char v)
{
	t_stack	*tail;
	t_stack	*head;

	head = *stack;
	if (!head || !head->next)
		return ;
	tail = *stack;
	while (tail->next->next)
		tail = tail->next;
	tail->next->next = head;
	*stack = tail->next;
	tail->next = NULL;
	if (v != ' ')
		ft_printf("rr%c\n", v);
}

void	p_ab(t_stack **orig, t_stack **dest, char v)
{
	t_stack	*o_head;
	t_stack	*d_head;

	o_head = *orig;
	d_head = *dest;
	if (!o_head)
		return ;
	if (!o_head->next)
		*orig = NULL;
	else
		*orig = o_head->next;
	if (d_head)
		o_head->next = d_head;
	else
		o_head->next = NULL;
	*dest = o_head;
	if (v == 'a' || v == 'b')
		ft_printf("p%c\n", v);
}

void	sort3_elem(t_stack **stack, char v)
{
	while (!is_ordered(stack))
	{
		if (find_bigger(stack) == 0)
			rr_ab(stack, v);
		else if (find_bigger(stack) == 1)
			r_ab(stack, v);
		else if (find_bigger(stack) == 2)
			s_ab(stack, v);
	}
}
