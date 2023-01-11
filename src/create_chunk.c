/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:02 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/11 10:53:25 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
void print_list(t_element **list_a, t_element **list_b);
// Esta función mira a ver cual es el minimo index del chunk para saber el rango del chunk.  es decir si estamos en 0-19 o 20-9 etc.
int chunk_range(t_element **stack_b, int num_in_ch)
{
	int min_in_chunk;
	int n;

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

// una vez que vamos pasando numeros al stack_b colocamos los mas altos de cada chunk mas arriba que los mas bajos de cada chunk ( hasta conseguir la forma de reloj de arena en el stack_b)

void organize_stack_b(t_element **stack_b, t_element **stack_a, int num_in_ch)
{
	int max_in_chunk;
	int min_in_chunk;
	int total_len;

	if (lst_size(*stack_b) == 1 || lst_size(*stack_b) == 0)
		return;
	total_len = lst_size(*stack_a) + lst_size(*stack_b);
	max_in_chunk = chunk_range(stack_b, num_in_ch) + num_in_ch;
	min_in_chunk = chunk_range(stack_b, num_in_ch);
	if (total_len < num_in_ch)
		max_in_chunk = total_len;
	if ((*stack_b)->index < min_in_chunk + 10)
	{
		if (*stack_a && (*stack_a)->index > max_in_chunk)
			print_do_rotate_both(stack_a, stack_b);
		else
			print_do_rotate(stack_b, 'b');
	}
}

int move_in_stack_b(t_element **stack_a, t_element **stack_b, int length, int i)
{
	int active_swap;
	(void)**stack_a;

	int max;


	max= lst_size(*stack_b) - 1;
	active_swap = 0;
	//printf("buscando el :%d\n", max);
	while (*stack_b && (*stack_b)->index != max)
	{

		if ((*stack_b)->index == max - 1)
		{
			print_do_push(stack_a, stack_b, 'a');
			active_swap = 1;
			//write(1, "encontrado11\n", 13);
			if(!(*stack_b && (*stack_b)->next))
			{
			//	write(1, "fallo\n", 6);
				break ;
				}
			//write(1, "encontrado\n", 11);
		}
		if (i <= length / 2)
			print_do_rotate(stack_b, 'b');
		else
			print_do_rrotate(stack_b, 'b');
	}
	//write(1,"max",3);

	return(active_swap);

	/*if (i <= length / 2)
	{
		while ((*stack_b) != lst_size(*stack_b) - 1)
		{
			if ((*stack_b)->index == lst_size(*stack_b) - 2)
			{
				print_do_push(stack_a, stack_b, 'a');
				write(1, "encontrado\n", 11);
			}

			print_do_rotate(stack_b, 'b');
		}
	}
	else
	{
		while ((*stack_b) != lst_size(*stack_b) - 1)
		{
			if ((*stack_b)->index == lst_size(*stack_b) - 2)
			{
				print_do_push(stack_a, stack_b, 'a');
				write(1, "encontrado2\n", 12);
			}
			print_do_rrotate(stack_b, 'b');
		}
	}*/
}

void move_in_stack_a(t_element **stack_b, int length, int i)
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
// luego organiza el stack_b y volvemos al siguiente numero de la lista con una length menos
int is_chunk(t_element **stack_a, t_element **stack_b, int length, int i)
{
	int num_in_ch;

	if (lst_size(*stack_a) + lst_size(*stack_b) > 100)
		num_in_ch = 62;
	else
		num_in_ch = 20;

	move_in_stack_a(stack_a, length, i);
	print_do_push(stack_a, stack_b, 'b');
	organize_stack_b(stack_b, stack_a, num_in_ch);
	length--;
	return length;
}

void back_to_stack_a(t_element **stack_b, t_element **stack_a)
{
	int max;
	t_element *t;
	// t_element *last;
	int i;

	i = 0;
	t = *stack_b;
	max = lst_size(*stack_b) - 1;
	while (t)
	{
		// last = lst_last(t);
		if (t->index == max)
		{
			if(move_in_stack_b(stack_a, stack_b, lst_size(*stack_b), i))
			{
			//	write(1, "push_swap\n", 10);
				print_do_push(stack_a, stack_b, 'a');
				print_do_swap(stack_a, 'a');
				max--;
			}
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

void sort_100_500(t_element **stack_a, t_element **stack_b, int len, int num_in_ch)
{
	t_element *t;
	int i;
	int min_in_chunk;
	int new_len;

	i = 0;
	t = *stack_a;
	new_len = len;
	while (t)
	{
		min_in_chunk = chunk_range(stack_b, num_in_ch);
		if (t->index >= min_in_chunk && t->index < min_in_chunk + num_in_ch)
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
