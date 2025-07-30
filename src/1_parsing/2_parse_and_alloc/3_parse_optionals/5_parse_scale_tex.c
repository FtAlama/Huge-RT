/* ************************************************************************** */
/*                                                                            */
/*   3_parse_textures.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:39:13 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

bool	has_scale_tex(char *s)
{
	if (ft_strncmp(s, "scale_tex(", 10) == EXIT_SUCCESS)
		return (true);
	return (false);
}

void	parse_scale_tex(t_object *o, char **line)
{
	t_tuple	tmp;
	t_mat4	scale;

	tmp = vector(1, 1, 1);
	adv_next_word(line);
	consume_paren(line);
	tmp.x = get_next_float(line);
	tmp.y = get_next_float(line);
	tmp.z = get_next_float(line);
	scale = scaling(tmp.x, tmp.y, tmp.z);
	o->material.pattern.trans = multi_mat4(o->material.pattern.trans, scale);
}
