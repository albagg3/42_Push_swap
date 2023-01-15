/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:36:55 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:40:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int	move_in_stack_b(t_elem **stack_a, t_elem **stack_b, int length, int i)
{
	int	active_swap;
	int	max;

	max = lst_size(*stack_b) - 1;
	active_swap = 0;
	while (*stack_b && (*stack_b)->index != max)
	{
		if ((*stack_b)->index == max - 1)
		{
			print_do_push(stack_a, stack_b, 'a');
			active_swap = 1;
			if (!(*stack_b && (*stack_b)->next))
				break ;
			if ((*stack_b)->index == max)
				return (1);
		}
		if (i <= length / 2)
			print_do_rotate(stack_b, 'b');
		else
			print_do_rrotate(stack_b, 'b');
	}
	return (active_swap);
}

int	resort_a(t_elem **stack_a, t_elem **stack_b, int max)
{
	print_do_push(stack_a, stack_b, 'a');
	print_do_swap(stack_a, 'a');
	max--;
	return (max);
}

void	back_to_stack_a(t_elem **stack_b, t_elem **stack_a)
{
	int			max;
	t_elem		*t;
	int			i;

	i = 0;
	t = *stack_b;
	max = lst_size(*stack_b) - 1;
	while (t)
	{
		if (t->index == max)
		{
			if (move_in_stack_b(stack_a, stack_b, lst_size(*stack_b), i))
				max = resort_a(stack_a, stack_b, max);
			else
				print_do_push(stack_a, stack_b, 'a');
			t = *stack_b;
			max--;
			i = 0;
		}
		else
		{
			i++;
			t = t->next;
		}
	}
}

void	sort_long(t_elem **stack_a, t_elem **stack_b, int len, int num_ch)
{
	t_elem	*t;
	int		i;
	int		min_in_chunk;
	int		new_len;

	i = 0;
	t = *stack_a;
	new_len = len;
	while (t)
	{
		min_in_chunk = chunk_range(stack_b, num_ch);
		if (t->index >= min_in_chunk && t->index < min_in_chunk + num_ch)
		{
			new_len = is_chunk(stack_a, stack_b, new_len, i);
			t = *stack_a;
			i = 0;
		}
		else
		{
			i++;
			t = t->next;
		}
	}
	*stack_a = NULL;
	back_to_stack_a(stack_b, stack_a);
}
