/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:56 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/07 21:14:11 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

void	radix_sort(t_stack **a, t_stack **b, int size, char v)
{
	int		max;
	int		bits;
	int		i;
	int		j;

	i = -1;
	bits = 0;
	max = size - 1;
	while (max >> bits != 0)
		bits++;
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->pos >> i) & 1) == 1)
				r_ab(a, v);
			else
				p_ab(a, b, rev_v(v));
		}
		while (stack_len(b) > 0)
			p_ab(b, a, v);
	}
}

void	sort_pos(t_stack **a, t_stack **aux)
{
	t_stack	*aux_head;
	t_stack	*head;
	int		x;

	head = *a;
	while (head)
	{
		x = 0;
		aux_head = *aux;
		while (aux_head)
		{
			if (aux_head->num == head->num)
			{
				head->pos = x;
				break ;
			}
			x++;
			aux_head = aux_head->next;
		}
		head = head->next;
	}
}
