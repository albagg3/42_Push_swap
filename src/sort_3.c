/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:33 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 14:06:49 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>

int	min_index_in_stack(t_elem **stack)
{
	t_elem		*temp;
	int			i;

	temp = *stack;
	i = temp->index;
	while (temp)
	{
		if (i > temp->index)
			i = temp->index;
		temp = temp->next;
	}
	return (i);
}

int	is_not_sorted(t_elem **stack)
{
	t_elem		*temp;
	int			i;

	temp = *stack;
	i = min_index_in_stack(stack);
	while (temp)
	{
		if (temp->index == i)
		{
			i++;
			temp = temp->next;
		}
		else
			return (1);
	}
	return (0);
}

void	sort_3(t_elem **stack, int length, int min_i)
{
	t_elem	*t;

	t = *stack;
	if (length == 2)
	{
		if (t->index > t->next->index)
			print_do_swap(stack, 'a');
		else
			return ;
	}
	else
	{
		while (is_not_sorted(stack))
		{
			t = *stack;
			if ((t->index == min_i && t->next->index == min_i + 2) || \
				(t->index == min_i + 2 && t->next->index == min_i + 1) || \
					(t->index == min_i + 1 && t->next->index == min_i))
				print_do_swap(stack, 'a');
			else if (t->index == min_i + 2 && t->next->index == min_i)
				print_do_rotate(stack, 'a');
			else
				print_do_rrotate(stack, 'a');
		}
	}
}
