/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:30:52 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:31:24 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stddef.h>
#include "../inc/utils.h"
#include <stdio.h>

void	swap_element(t_elem **stack)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	if (third)
	{
		first->next = third;
		third->previous = first;
	}
	else
		first->next = NULL;
	*stack = second;
}

void	push_element(t_elem **stack_1, t_elem **stack_2)
{
	t_elem	*first_1;
	t_elem	*first_2;

	first_1 = *stack_1;
	first_2 = *stack_2;
	if (first_2 == NULL)
	{
		first_1->next->previous = NULL;
		*stack_1 = first_1->next;
		*stack_2 = first_1;
		first_1->next = NULL;
	}
	if (first_2)
	{
		if (first_1->next == NULL)
			*stack_1 = NULL;
		else
		{
			first_1->next->previous = NULL;
			*stack_1 = first_1->next;
		}
		first_2->previous = first_1;
		first_1->next = first_2;
		*stack_2 = first_1;
	}
}

void	reverse_rotate_element(t_elem **stack)
{
	t_elem	*last;
	t_elem	*first;

	if (!(*stack && (*stack)->next))
		return ;
	first = *stack;
	last = lst_last(first);
	last->previous->next = NULL;
	first->previous = last;
	last->previous = NULL;
	last->next = first;
	*stack = last;
}

void	rotate_element(t_elem **stack)
{
	t_elem	*last;
	t_elem	*first;

	if (!(*stack && (*stack)->next))
		return ;
	first = *stack;
	last = lst_last(first);
	first->next->previous = NULL;
	*stack = first->next;
	first->next = NULL;
	first->previous = last;
	last->next = first;
}
