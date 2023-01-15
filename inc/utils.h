/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:55:26 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:54:30 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../inc/defines.h"

int			ft_is_number(char *str);
int			ft_is_int(char *str);
void		ft_is_dup(char **argv, int length);
t_elem		*lst_new(int content);
t_elem		*lst_last(t_elem *lst);
void		lst_add_back(t_elem **first, t_elem *new_el);
void		set_index(t_elem **first);
void		swap_element(t_elem **swap);
void		push_element(t_elem **stack_a, t_elem **stack_b);
void		reverse_rotate_element(t_elem **stack);
void		rotate_element(t_elem **stack);
void		sort_3(t_elem **stack, int length, int min_index);
void		sort_5(t_elem **stack_1, t_elem **stack_2, int length);
void		print_do_swap(t_elem **stack, char stack_name);
void		print_do_push(t_elem **stack_1, t_elem **stack_2, char stack_name);
void		print_do_rotate(t_elem **stack, char stack_name);
void		print_do_rrotate(t_elem **stack, char stack_name);
void		print_do_swap_both(t_elem **stack1, t_elem **stack2);
void		print_do_rotate_both(t_elem **stack1, t_elem **stack2);
void		print_do_rrotate_both(t_elem **stack1, t_elem **stack2);
int			min_index_in_stack(t_elem **stack);
void		sort_long(t_elem **stack_a, t_elem **stack_b, int len, int num_ch);
int			lst_size(t_elem *lst);
int			is_not_sorted(t_elem **stack);
int			chunk_range(t_elem **stack_b, int num_in_ch);
int			is_chunk(t_elem **stack_a,t_elem **stack_b, int length, int i);
void		move_in_stack_a(t_elem **stack_a, int length, int i);

#endif
