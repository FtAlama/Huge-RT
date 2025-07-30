/* ************************************************************************** */
/*                                                                            */
/*   metal1_material.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	gold_object(t_object *o)
{
	o->material.ambient = 0.1;
	o->material.diffuse = 0.6;
	o->material.specular = 0.3;
	o->material.shininess = 15;
}

void	silver_object(t_object *o)
{
	o->material.ambient = 0.1;
	o->material.diffuse = 0.7;
	o->material.specular = 0.3;
	o->material.shininess = 15;
}

void	white_object(t_object *o)
{
	o->material.ambient = 0.1;
	o->material.diffuse = 0.7;
	o->material.specular = 0.1;
	o->material.reflective = 0.1;
}

void	metal4_object(t_object *o)
{
	o->material.ambient = 0.0;
	o->material.diffuse = 0.2;
	o->material.specular = 1.0;
	o->material.shininess = 200;
	o->material.reflective = 0.7;
	o->material.transparency = 0.7;
	o->material.refractive_index = 1.5;
}
