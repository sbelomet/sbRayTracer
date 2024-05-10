/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:35 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/10 12:44:13 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_sphere_hit(const void *sphere_obj, const t_ray r, t_hit_rec *rec)
{
	t_sphere	*sphere;
	t_equation	quad;
	t_vector3	vhat;

	sphere = (t_sphere *)sphere_obj;
	(void)sphere;
	vhat = ft_vec3_unit(r.lab);
	quad.a = 1;
	quad.b = 2 * ft_vec3_dot(r.p1, vhat);
	quad.c = ft_vec3_dot(r.p1, r.p1) - 1;
	quad.t = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.t > 0)
	{
		quad.t = sqrt(quad.t);
		quad.t1 = (-quad.b + quad.t) / 2.0;
		quad.t2 = (-quad.b - quad.t) / 2.0;
		if (quad.t1 < 0 || quad.t2 < 0)
			return (false);
		else
		{
			if (quad.t1 < quad.t2)
				rec->p = ft_vec3_add(r.p1, ft_vec3_mult(vhat, quad.t1));
			else
				rec->p = ft_vec3_add(r.p1, ft_vec3_mult(vhat, quad.t2));
			rec->normal = ft_vec3_unit(rec->p);
		}
		return (true);
	}
	else
		return (false);
}

int	ft_hit_anything(t_objects *list, const t_ray r, t_hit_rec *rec, t_light *lights)
{
	t_objects	*tmp_list;
	t_hit_rec	tmp_rec;
	int			hit_anything;

	tmp_list = list;
	hit_anything = false;
	while (tmp_list)
	{
		if (tmp_list->ft_hit(tmp_list->object, r, &tmp_rec))
		{
			if (ft_calc_lights(list, tmp_list, &tmp_rec, lights))
			{
				hit_anything = true;
				rec->p = tmp_rec.p;
				rec->normal = tmp_rec.normal;
				rec->color = tmp_rec.color;
				rec->intensity = tmp_rec.intensity;
			}
		}
		tmp_list = tmp_list->next;
	}
	return (hit_anything);
}
