/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:59:16 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 14:00:50 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/utils.h"
#include "../inc/defines.h"
#include <unistd.h>

void	print_do_rotate(t_elem **stack, char stack_name)
{
	if (stack_name == 'a')
	{
		rotate_element(stack);
		write(1, "ra\n", 3);
	}
	if (stack_name == 'b')
	{
		rotate_element(stack);
		write(1, "rb\n", 3);
	}
}

void	print_do_rotate_both(t_elem **stack_a, t_elem **stack_b)
{
	rotate_element(stack_a);
	rotate_element(stack_b);
	write(1, "rr\n", 3);
}

void	print_do_rrotate(t_elem **stack, char stack_name)
{
	if (stack_name == 'a')
	{
		reverse_rotate_element(stack);
		write(1, "rra\n", 4);
	}
	if (stack_name == 'b')
	{
		reverse_rotate_element(stack);
		write(1, "rrb\n", 4);
	}
}

void	print_do_rrotate_both(t_elem **stack_a, t_elem **stack_b)
{
	reverse_rotate_element(stack_a);
	reverse_rotate_element(stack_b);
	write(1, "rrr\n", 4);
}
