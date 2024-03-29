/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:46 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/15 13:13:05 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#define ERR_NOARGS "Error: Please write some numbers"
#define ERR_ARGSRP "Error: Please make sure there are not repeated numbers"
#define ERR_NBR "Error: Please make sure all the inputs are numbers"
#define ERR_INT "Error: Please make sure all the numbers are int"*/

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NOARGS "Error"
# define ERR_ARGSRP "Error"
# define ERR_NBR "Error"
# define ERR_INT "Error"

void	terminate(char *s);

#endif
