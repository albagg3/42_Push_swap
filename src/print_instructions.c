/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:58:04 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/08 20:59:55 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/defines.h"
#include <unistd.h>

void print_do_swap(t_element **stack, char stack_name)
{
	if(stack_name == 'a' /*&& *stack_a*/)
	{	
		swap_element(stack);
		write(1, "sa\n", 3);
	}
	if(stack_name == 'b' /*&& *stack_b*/)
	{
		swap_element(stack);
		write(1, "sb\n", 3);
	}
}

void print_do_swap_both(t_element **stack_a, t_element **stack_b)
{
	swap_element(stack_a);
	swap_element(stack_b);
	write(1, "ss\n", 3);
}

void print_do_push(t_element **stack_1, t_element **stack_2, char stack_name)
{
	if(stack_name == 'b' /*&& *stack_1*/)
	{	
		push_element(stack_1, stack_2);
		write(1, "pb\n", 3);
	}
	if(stack_name == 'a'/* && *stack_2*/)
	{
		push_element(stack_2,stack_1);
		write(1, "pa\n", 3);
	}
}

void print_do_rotate(t_element **stack, char stack_name)
{
	if(stack_name == 'a' /*&& *stack_a*/)
	{	
		rotate_element(stack);
		write(1, "ra\n", 3);
	}
	if(stack_name == 'b' /*&& *stack_b*/)
	{
		rotate_element(stack);
		write(1, "rb\n", 3);
	}
}

void print_do_rotate_both(t_element **stack_a, t_element **stack_b)
{
	rotate_element(stack_a);
	rotate_element(stack_b);
	write(1, "rr\n", 3);
}

void print_do_rrotate(t_element **stack, char stack_name)
{
	if(stack_name == 'a'/* && *stack_a*/)
	{	
		reverse_rotate_element(stack);
		write(1, "rra\n", 4);
	}
	if(stack_name == 'b'/* && *stack_b*/)
	{
		reverse_rotate_element(stack);
		write(1, "rrb\n", 4);
	}
}

void print_do_rrotate_both(t_element **stack_a, t_element **stack_b)
{
	reverse_rotate_element(stack_a);
	reverse_rotate_element(stack_b);
	write(1, "rrr\n", 4);
	
}
