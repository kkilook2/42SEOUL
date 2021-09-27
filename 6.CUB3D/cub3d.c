/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:03:14 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/28 12:13:00 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
typedef struct		s_screen{
	void	*win;
	void	*mlx;
	t_img	img;
	t_pixel **pixel;
	t_vec	origin;
	t_vec	dir;
	t_vec	plane;
	double	sin_unit;
	double	cos_unit;
	double	distance;
	t_ray	*ray;
	int		w;
	int		h;
}					t_screen;

typedef struct		s_img{
	int		w;
	int		h;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*ptr;
	unsigned int	*addr;
}					t_img;

typedef struct		s_vec{
	double x;
	double y;
}					t_vec;

typedef struct		s_pixel{
	double distance;
	unsigned *color;
}					t_pixel;

typedef struct		s_ray{
	t_vec	dir;
	double	distance;
}					t_ray;

t_vec		set_player_plane(t_map *map, int w)
{
	double	min;

	min = tan(FOV / 2) / w * 2;
	if (map->dir_init == 'E')
		return vec_new(0, -min);
}

t_pixel		**init_pixel(int w, int h, t_img *img)
{
	t_pixel **pixel;
	int		x;
	int		y;

	pixel = malloc(sizeof(t_pixel*) * w);
	x = -1;
	while (++x < w)
	{
		y = -1;
		pixel[x] = malloc(sizeof(t_pixel) * h);
		while (++y < h)
		{
			pixel[x][y].distance = INFINITY;
			pixel[x][y].color = (unsigned int*)((char*)img->addr + img->size_line * y 
								+ img->bits_per_pixel / 8 * x);
		}
	}
	return (pixel);
}


int	main()
{
	t_screen screen;
	t_screen *s;

	s = &screen;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->w, s->h, "cub3d lesson");
	s->img.ptr = mlx_new_image(s->mlx, s->w, s->h);
	s->img.addr = (unsigned int*)mlx_get_data_addr(s->img.ptr, &(s->img.bits_per_pixel), 
						&(s->img.size_line), &(s->img.endian));
	s->distance = 1 / tan(FOV / 2) *  s->w / 2;
	s->pixel = init_pixel(s->w, s->h, &s->img);
}

