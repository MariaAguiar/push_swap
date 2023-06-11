/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:56 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/10 11:02:26 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

t_stack	*get_tail(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*new_elem(int value)
{
	t_stack	*val;

	val = malloc(sizeof(*val));
	if (!val)
		return (NULL);
	val->num = value;
	val->pos = 0;
	val->next = NULL;
	return (val);
}

t_stack	*add_elem(t_stack **stack, int value)
{
	t_stack	*head;
	t_stack	*new;

	head = *stack;
	new = new_elem(value);
	if (!head)
	{
		*stack = new;
		return (*stack);
	}
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
		return (head);
	}
}

void	sortall_elem(t_stack **a)
{
	t_stack	*aux;
	t_stack	*b;

	aux = NULL;
	b = NULL;
	aux = new_aux(a, &aux, stack_len(a));
	sort5_elem(&aux, ' ');
	sort_pos(a, &aux);
	radix_sort(a, &b, stack_len(a), 'a');
	if (b)
		clear_stack(&b);
	if (aux)
		clear_stack(&aux);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	stack_a = valid_arr(argc, argv, &stack_a);
	if (!stack_a && argc > 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	argc = stack_len(&stack_a) + 1;
	if (stack_a && argc > 2 && !(is_ordered(&stack_a)))
	{
		if (argc == 3)
			s_ab(&stack_a, 'a');
		else if (argc == 4)
			sort3_elem(&stack_a, 'a');
		else if (argc > 4 && argc <= 50)
			sort5_elem(&stack_a, 'a');
		else if (argc > 50)
			sortall_elem(&stack_a);
	}
	clear_stack(&stack_a);
	return (0);
}
