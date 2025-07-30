/* ************************************************************************** */
/*                                                                            */
/*   0_main.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:27:44 by afocant           #+#    #+#             */
/*   Updated: 2025/07/29 15:26:42 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_progress(float y, float max)
{
	printf("\rRendering [%3.0f%%]\r", y / max * 100);
	if (y == max - 1)
		printf("\rRendering [100%%]\nRendering Done\n");
	fflush(stdout);
}

void	render(t_camera c, t_world *w, t_mlx_data *m_data)
{
	int		y;
	int		x;
	t_ray	r;
	t_color	pixel_color;

	y = 0;
	while (y < c.vsize)
	{
		print_progress((float) y, (float) c.vsize);
		x = 0;
		while (x < c.hsize)
		{
			r = ray_to_world_pixel(c, x, y);
			pixel_color = color_at(w, r, MAX_RECURSION);
			my_mlx_pixel_put(m_data, x, y, vec_to_hex_color(pixel_color));
			x++;
		}
		y++;
	}
}

void	render_with_mlx(t_world *w, char *filename)
{
	t_mlx		mlx;
	t_mlx_data	m_data;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, filename);
	m_data.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	m_data.addr = mlx_get_data_addr(m_data.img,
			&m_data.bits_per_pixel, &m_data.line_length, &m_data.endian);
	mlx.data = &m_data;
	events_init(&mlx);
	activate_textures(w, &mlx);
	render(w->camera, w, &m_data);
	ft_free_tex_world(w, &mlx);
	free(w->obj);
	free(w->lights);
	mlx_put_image_to_window(mlx.mlx, mlx.win, m_data.img, 0, 0);
	mlx_loop(mlx.mlx);
}

int	main(int ac, char **av)
{
	t_world	w;

	if (ac != 2)
		error_exit("Usage: needs .rt input file\n");
	w = parse_argfile(*(av + 1));
	render_with_mlx(&w, *(av + 1));
	exit(EXIT_SUCCESS);
}
