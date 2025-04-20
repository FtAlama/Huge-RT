/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:18:26 by alama             #+#    #+#             */
/*   Updated: 2025/04/20 17:33:00 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	point(float x, float y, float z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1.0;
	return (p);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 0.0;
	return (vec);
}

t_tuple	err_tuple(void)
{
	t_tuple	err;

	err.w = -1;
	return (err);
}

void	print_tuple(t_tuple t)
{
	if (t.w == -1)
		return (printf("wrong tuples\n"), (void) NULL);
	printf("the tuple is a : ");
	if (t.w == 0)
		printf("vector\n");
	else
		printf("point\n");
	printf("the coordinate are : x : %f, y : %f, z : %f\n", t.x, t.y, t.z);
}
