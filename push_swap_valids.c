/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_valids.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:56 by mnascime          #+#    #+#             */
/*   Updated: 2023/03/10 11:21:25 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#	include "libft/libft.h"

t_stack	*valid_arr(int argc, char **argv, t_stack **stack)
{
	t_stack	*head;
	int		x;
	int		y;

	x = 0;
	y = -1;
	head = *stack;
	while (++x < argc)
	{
		if (atoiable(argv[x]) && not_found(stack, ft_atoi(argv[x])))
			head = add_elem(stack, ft_atoi(argv[x]));
		else if (splitable(stack, argv[x]))
			continue ;
		else
			break ;
	}
	if (x != argc)
	{
		clear_stack(stack);
		return (0);
	}
	head = *stack;
	return (head);
}

int	atoiable(char *num)
{
	size_t	x;
	int		y;
	char	*renum;

	x = 0;
	y = 1;
	renum = ft_itoa(ft_atoi(num));
	if (ft_strlen(num) != ft_strlen(renum))
	{
		while (num[x] == 48 || (num[x] == '-' && x == 0)
			|| (num[x] == '+' && x == 0))
			x++;
		if (num[0] == '-')
			x--;
		if ((!(ft_strlen(num) == ft_strlen(renum) + x))
			&& (!(x == ft_strlen(num))))
			y = 0;
	}
	else if (!(*renum == 48 && *num == 48) && !ft_atoi(num))
		y = 0;
	free(renum);
	return (y);
}

int	not_found(t_stack **stack, int value)
{
	t_stack	*head;

	head = *stack;
	while (head)
	{
		if (head->num == value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	splitable(t_stack **stack, char *num)
{
	t_stack	*head;
	char	**splits;
	int		x;
	int		y;

	x = -1;
	y = 1;
	head = *stack;
	splits = ft_split(num, ' ');
	if (!no_repeat(splits))
		y = 0;
	while (splits[++x])
	{
		if (!(atoiable(splits[x]) && not_found(stack, ft_atoi(splits[x]))))
			y = 0;
	}
	x = -1;
	while (y == 1 && splits[++x])
		head = add_elem(stack, ft_atoi(splits[x]));
	while (splits[--x] && x >= 0)
		free(splits[x]);
	free(splits);
	return (y);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
		temp = NULL;
	}
	stack = NULL;
}
