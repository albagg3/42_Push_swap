/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:04 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 14:00:48 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/defines.h"
#include <unistd.h>

void	print_do_swap(t_elem **stack, char stack_name)
{
	if (stack_name == 'a')
	{	
		swap_element(stack);
		write(1, "sa\n", 3);
	}
	if (stack_name == 'b')
	{
		swap_element(stack);
		write(1, "sb\n", 3);
	}
}

void	print_do_swap_both(t_elem **stack_a, t_elem **stack_b)
{
	swap_element(stack_a);
	swap_element(stack_b);
	write(1, "ss\n", 3);
}

void	print_do_push(t_elem **stack_1, t_elem **stack_2, char stack_name)
{
	if (stack_name == 'b')
	{	
		push_element(stack_1, stack_2);
		write(1, "pb\n", 3);
	}
	if (stack_name == 'a')
	{
		push_element(stack_2, stack_1);
		write(1, "pa\n", 3);
	}
}
