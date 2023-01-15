/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:03:16 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:58:28 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/errors.h"
#include "../lib/libft_src/libft.h"
#include "../inc/utils.h"
#include <stdio.h>

void	lstfree(t_elem **lst)
{
	t_elem	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		while (temp != NULL)
		{
			free (temp);
			temp = temp->next;
		}
		*lst = NULL;
	}
}

void	check_number_arguments(t_elem **stack_1, t_elem **stack_2, int length)
{
	int	min_index;

	min_index = min_index_in_stack(stack_1);
	if (length == 1)
		exit (0);
	if (length > 1 && length <= 3)
		sort_3(stack_1, length, min_index);
	if (length > 3 && length <= 5)
		sort_5(stack_1, stack_2, length);
	if (length > 5 && length <= 100)
		sort_long(stack_1, stack_2, length, 20);
	if (length > 100)
		sort_long(stack_1, stack_2, length, 62);
	lstfree(stack_1);
}

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	t_elem	*temp;
	int		i;

	b = NULL;
	i = 1;
	if (argc >= 2)
	{
		ft_is_dup(argv, argc - 1);
		while (argv[i])
		{
			temp = lst_new(ft_atoi(argv[i]));
			lst_add_back(&a, temp);
			i++;
		}
		set_index(&a);
		if (is_not_sorted(&a))
			check_number_arguments(&a, &b, argc - 1);
		lstfree(&a);
	}
	else
		terminate(ERR_NOARGS);
}

/*
void	print_list (t_elem **list_a, t_elem **list_b)
{
	t_elem *temp_a;
	t_elem *temp_b;

	temp_a = *list_a;
	temp_b = *list_b;
	while (temp_a)
	{
		printf("valor en lista_1:%d, valor en index:%d\n",\
	   	temp_a->value, temp_a->index);
		temp_a = temp_a->next;
	}

	printf("----------------------------------------\n");

	while(temp_b)
	{
		printf("valor en lista_2:%d, valor en index:%d\n",\
	   	temp_b->value, temp_b->index);
		temp_b = temp_b->next;
	}
}*/
