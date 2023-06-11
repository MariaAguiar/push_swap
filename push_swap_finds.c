/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_finds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:25:09 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/10 11:21:35 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

int	is_ordered(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_bigger(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	if (head->next->next != NULL)
	{
		if (head->next->num > head->next->next->num
			&& head->next->num > head->num)
			return (0);
		if ((head->next->num < head->next->next->num)
			&& (head->next->next->num > head->num))
			return (2);
	}
	return (1);
}

char	rev_v(char v)
{
	if (v == 'a')
		return ('b');
	else if (v == 'b')
		return ('a');
	else
		return (' ');
}

t_stack	*new_aux(t_stack **stack, t_stack **aux, int lim)
{
	t_stack	*aux_head;
	t_stack	*head;
	int		x;

	x = 0;
	head = *stack;
	aux_head = *aux;
	while (head && x < lim)
	{
		aux_head = add_elem(aux, head->num);
		head = head->next;
		x++;
	}
	aux_head = *aux;
	return (aux_head);
}

int	no_repeat(char **splits)
{
	int		x;
	int		y;

	x = -1;
	while (splits[++x])
	{
		y = -1;
		while (splits[++y])
		{
			if (x != y && ft_atoi(splits[x]) == ft_atoi(splits[y]))
				return (0);
		}
	}
	return (1);
}
