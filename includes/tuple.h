/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:45:02 by alama             #+#    #+#             */
/*   Updated: 2025/04/20 16:33:13 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "mini_rt.h"

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	*point(float x, float y, float z);
t_tuple	*vector(float x, float y, float z);
t_tuple	*add_tuple(t_tuple a, t_tuple b);
t_tuple	*sub_tuple(t_tuple a, t_tuple b);
void	print_tuple(t_tuple *t);

#endif
