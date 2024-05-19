/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:47:15 by lgosselk          #+#    #+#             */
/*   Updated: 2024/05/19 13:23:43 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_objects	*ft_objects_init(void)
{
	t_objects	*list;
	t_sphere	*s;
	t_plane		*p;
	
	list = NULL;
	s = (t_sphere *)malloc(sizeof(t_sphere));
	ft_gtf_set_transform(&s->tm, ft_vec3_new(-1.5, 0, 0), ft_vec3_new(0, 0, 0), ft_vec3_new(.5, .5, .75));
	s->color = ft_color_new(0, .25, .5, .78);
	s->mat = ft_mat_new(ft_comp_diffuse_color);
	ft_object_add(&list, ft_object_new(s, SPHERE));
	s = (t_sphere *)malloc(sizeof(t_sphere));
	ft_gtf_set_transform(&s->tm, ft_vec3_new(0, 0, 0), ft_vec3_new(0, 0, 0), ft_vec3_new(.75, .5, .5));
	s->color = ft_color_new(0, 1, .55, 0);
	s->mat = ft_mat_new(ft_comp_diffuse_color);
	ft_object_add(&list, ft_object_new(s, SPHERE));
	s = (t_sphere *)malloc(sizeof(t_sphere));
	ft_gtf_set_transform(&s->tm, ft_vec3_new(1, -.5, 0), ft_vec3_new(0, 0, 0), ft_vec3_new(.75, .75, .75));
	s->color = ft_color_new(0, 1, .9, 0);
	s->mat = ft_mat_new(ft_comp_diffuse_color);
	ft_object_add(&list, ft_object_new(s, SPHERE));
	p = (t_plane *)malloc(sizeof(t_plane));
	ft_gtf_set_transform(&p->tm, ft_vec3_new(0, 0, .75), ft_vec3_new(0, 0, 0), ft_vec3_new(4, 4, 1));
	p->color = ft_color_new(0, .75, .75, .75);
	p->mat = ft_mat_new(ft_comp_diffuse_color);
	ft_object_add(&list, ft_object_new(p, PLANE));
	return (list);
}

t_light	*ft_lights_init(void)
{
	t_light	*list;

	list = NULL;
	ft_light_add(&list, ft_light_new(ft_vec3_new(5, -10, -5), ft_color_new(0, 0, 0, 1), 1));
	ft_light_add(&list, ft_light_new(ft_vec3_new(-5, -10, -5), ft_color_new(0, 1, 0, 0), 1));
	ft_light_add(&list, ft_light_new(ft_vec3_new(0, -10, -5), ft_color_new(0, 0, 1, 0), 1));
	return (list);
}

int	ft_base_init(t_base *base)
{
	base->alloc = NULL;
	base->exit_code = 0;
	base->mlx_ptr = mlx_init();
	if (!base->mlx_ptr)
		return (print_error(MLX_ERR, NULL, 1), set_exit_code(base, 1, 1));
	base->win_ptr = mlx_new_window(base->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (!base->win_ptr)
		return (print_error(WIN_ERR, NULL, 1), set_exit_code(base, 1, 1));
	base->image.img_ptr = mlx_new_image(base->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!base->image.img_ptr)
		return (print_error(IMG_ERR, NULL, 1), set_exit_code(base, 1, 1));
	base->image.img_data = mlx_get_data_addr(base->image.img_ptr,
			&base->image.bitsperpix, &base->image.size_line,
			&base->image.endian);
	base->seed = (unsigned long)&base;
	base->camera = ft_cam_new();
	if (!base->camera)
		return (print_error(CAM_ERR, NULL, 1), set_exit_code(base, 1, 1));
	base->first_object = ft_objects_init();
	base->first_light = ft_lights_init();
	return (0);
}
