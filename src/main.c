/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:58:49 by alama             #+#    #+#             */
/*   Updated: 2025/04/20 17:24:27 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(void)
{
	t_tuple	vec;
	t_tuple	p;
	t_tuple	add;
	t_tuple err;

	p= point(30.8, 00.5, 30.0);
	vec = vector(50.1, 10.5, 30.002005);
	printf("hello world\n");
	print_tuple(vec);
	print_tuple(p);
	printf("%d\n", equal_float(vec.z, p.z + 0.000005));
	add = add_tuple(vec, p);
	print_tuple(add);
	err = add_tuple(add, p);
	print_tuple(err);
	return (0);
}
