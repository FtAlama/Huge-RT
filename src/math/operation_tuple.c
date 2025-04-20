/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:18:52 by alama             #+#    #+#             */
/*   Updated: 2025/04/20 17:33:37 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	if (equal_float(a.w + b.w, 2))
		return (err_tuple());
	if (equal_float(a.w + b.w, 1))
		return (point(a.x + b.x, a.y + b.y, a.z + b.z));
	return (vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_tuple	subb_tuple(t_tuple a, t_tuple b)
{
	if (equal_float(a.w - b.w, -1))
		return (err_tuple());
	if (equal_float(a.w - b.w, 0))
		return (vector(a.x + b.x, a.y + b.y, a.z + b.z));
	return (point(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_tuple	negatif_tuple(t_tuple a)
{
	t_tuple	vec;

	vec = vector(0.0, 0.0, 0.0);
	return (subb_tuple(vec, a));
}
