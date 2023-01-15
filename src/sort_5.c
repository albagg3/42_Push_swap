/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:04:08 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 14:11:14 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>

int	is_min(int index)
{
	int	min_index;

	min_index = 0;
	if (index == min_index)
		return (1);
	else
		return (0);
}

int	next_min(int index)
{
	int	min_next_index;

	min_next_index = 1;
	if (index == min_next_index)
		return (1);
	else
		return (0);
}

int	lst_size(t_elem *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	sort_5_to_b(t_elem **stack_1, t_elem **stack_2, int length)
{
	t_elem	*t;
	t_elem	*last;

	t = *stack_1;
	last = lst_last(t);
	while (lst_size(t) > 3)
	{
		if (is_min(t->index) || (next_min(t->index) && length != 4))
			print_do_push(stack_1, stack_2, 'b');
		else if (is_min(t->next->index) || (next_min(t->next->index) && \
			length != 4))
		{
			print_do_swap(stack_1, 'a');
			print_do_push(stack_1, stack_2, 'b');
		}
		else if (is_min(last->index) || (next_min(last->index) && length != 4))
		{
			print_do_rrotate(stack_1, 'a');
			print_do_push(stack_1, stack_2, 'b');
		}
		else
			print_do_rotate(stack_1, 'a');
		t = *stack_1;
		last = lst_last(t);
	}
}

void	sort_5(t_elem **stack_1, t_elem **stack_2, int length)
{
	t_elem	*temp_2;
	int		min_index;

	temp_2 = *stack_2;
	if (!is_not_sorted(stack_1))
		return ;
	sort_5_to_b(stack_1, stack_2, length);
	min_index = min_index_in_stack(stack_1);
	sort_3(stack_1, length - 1, min_index);
	temp_2 = *stack_2;
	if (temp_2->index == 0)
	{
		if (lst_size(temp_2) == 2)
		{
			print_do_swap(stack_2, 'b');
			print_do_push(stack_1, stack_2, 'a');
		}
		print_do_push(stack_1, stack_2, 'a');
	}
	if (temp_2->index == 1)
	{
		print_do_push(stack_1, stack_2, 'a');
		print_do_push(stack_1, stack_2, 'a');
	}
}
