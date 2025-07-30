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

#include "prototypes_miniRT.h"

bool	has_is_shadow(char *s)
{
	if (ft_strncmp(s, "NO SHADOW", 9) == EXIT_SUCCESS)
		return (true);
	return (false);
}
