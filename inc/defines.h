/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:59:12 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:12:11 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_elem
{
	int					value;
	int					index;
	struct s_elem		*next;
	struct s_elem		*previous;
}t_elem;

#endif
