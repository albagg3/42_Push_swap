/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:02 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:54:22 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

// Esta función mira a ver cual es el minimo index del chunk para saber el 
// rango del chunk.  es decir si estamos en 0-19 o 20-9 etc.
int	chunk_range(t_elem **stack_b, int num_in_ch)
{
	int	min_in_chunk;
	int	n;

	min_in_chunk = num_in_ch;
	if (!*stack_b || lst_size(*stack_b) < num_in_ch)
		min_in_chunk = 0;
	else
	{
		n = lst_size(*stack_b) / num_in_ch;
		min_in_chunk *= n;
	}
	return (min_in_chunk);
}

// una vez que vamos pasando numeros al stack_b colocamos los mas altos de
//  cada chunk mas arriba que los mas bajos de cada chunk ( hasta conseguir la
//  forma de reloj de arena en el stack_b)

void	organize_stack_b(t_elem **stack_b, t_elem **stack_a, int num_in_ch)
{
	int	max_in_chunk;
	int	min_in_chunk;
	int	total_len;

	if (lst_size(*stack_b) == 1 || lst_size(*stack_b) == 0)
		return ;
	total_len = lst_size(*stack_a) + lst_size(*stack_b);
	max_in_chunk = chunk_range(stack_b, num_in_ch) + num_in_ch;
	min_in_chunk = chunk_range(stack_b, num_in_ch);
	if (total_len < num_in_ch)
		max_in_chunk = total_len;
	if ((*stack_b)->index < min_in_chunk + (num_in_ch / 2))
	{
		if (*stack_a && (*stack_a)->index > max_in_chunk)
			print_do_rotate_both(stack_a, stack_b);
		else
			print_do_rotate(stack_b, 'b');
	}
}

void	move_in_stack_a(t_elem **stack_b, int length, int i)
{
	if (i <= length / 2)
	{
		while (i)
		{
			print_do_rotate(stack_b, 'a');
			i--;
		}
	}
	if (i > length / 2)
	{
		while (i < length)
		{
			print_do_rrotate(stack_b, 'a');
			i++;
		}
	}
}

// si el numero es parte de un chunk lo pushea a la stack_b
// luego organiza el stack_b y volvemos al siguiente numero 
// de la lista con una length menos

int	is_chunk(t_elem **stack_a, t_elem **stack_b, int length, int i)
{
	int	num_in_ch;

	if (lst_size(*stack_a) + lst_size(*stack_b) > 100)
		num_in_ch = 62;
	else
		num_in_ch = 20;
	move_in_stack_a(stack_a, length, i);
	print_do_push(stack_a, stack_b, 'b');
	organize_stack_b(stack_b, stack_a, num_in_ch);
	length--;
	return (length);
}
