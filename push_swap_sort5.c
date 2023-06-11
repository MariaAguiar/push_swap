/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarida <margarida@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:56 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/06 22:37:37 by margarida        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

int	midpoint(t_stack **stack)
{
	int	x;

	x = stack_len(stack);
	if (x >= 1)
	{
		if (x % 2 == 0)
			x = (x / 2);
		else
			x = (x / 2) + 0.5;
		return (x);
	}
	return (0);
}

int	stack_len(t_stack **stack)
{
	t_stack	*head;
	int		x;

	x = 0;
	head = *stack;
	if (!head)
		return (x);
	while (head->next)
	{
		head = head->next;
		x++;
	}
	return (x + 1);
}

int	sml_num(t_stack **stack)
{
	t_stack	*head;
	int		mid;
	int		x;

	x = 0;
	head = *stack;
	mid = head->num;
	while (head->next)
	{
		head = head->next;
		if (head->num < mid)
			mid = head->num;
	}
	head = *stack;
	while (head->num != mid && head->next)
	{
		head = head->next;
		x++;
	}
	return (x);
}

int	sml_to_top(t_stack **stack, char v)
{
	int		x;
	int		y;

	x = sml_num(stack);
	y = midpoint(stack);
	while (x != 0 && !is_ordered(stack))
	{
		if (x > y)
			rr_ab(stack, v);
		else
			r_ab(stack, v);
		x = sml_num(stack);
	}
	if (is_ordered(stack))
		return (1);
	return (0);
}

void	sort5_elem(t_stack **a, char v)
{
	t_stack	*b;
	int		x;

	b = NULL;
	x = stack_len(a);
	while (!(is_ordered(a) && stack_len(a) == x))
	{
		if (!is_ordered(a) && stack_len(a) != 3)
		{		
			if (!sml_to_top(a, v))
				p_ab(a, &b, rev_v(v));
		}
		else if (!is_ordered(a) && stack_len(a) == 3)
			sort3_elem(a, v);
		else if (stack_len(a) != x)
		{
			p_ab(&b, a, v);
		}
	}
	if (b)
		clear_stack(&b);
}
