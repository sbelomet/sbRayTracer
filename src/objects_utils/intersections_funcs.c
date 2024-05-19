/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:35 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/19 12:40:37 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_plane_hit(const void *plane_obj, const t_ray r, t_hit_rec *rec)
{
	t_plane		*pl;
	t_ray		bck_r;
	t_vector3	k;
	double		t;
	double		uv[2];

	pl = (t_plane *)plane_obj;
	bck_r = ft_gtf_apply_ray(pl->tm, r, BCKFORM);
	k = ft_vec3_unit(bck_r.lab);
	if (!ft_close_enough(k.z, 0))
	{
		t = bck_r.p1.z / -k.z;
		if (t > 0)
		{
			uv[0] = bck_r.p1.x + (k.x * t);
			uv[1] = bck_r.p1.y + (k.y * t);
			if ((fabs(uv[0]) < 1) && (fabs(uv[1]) < 1))
			{
				rec->p = ft_vec3_add(bck_r.p1, ft_vec3_mult(k, t));
				rec->p = ft_gtf_apply_vec3(pl->tm, rec->p, FWDFORM);
				rec->normal = ft_vec3_unit(ft_vec3_sub(ft_gtf_apply_vec3(pl->tm, ft_vec3_new(0, 0, -1), FWDFORM),
								ft_gtf_apply_vec3(pl->tm, ft_vec3_new(0, 0, 0), FWDFORM)));
				rec->color = pl->color;
				rec->mat = pl->mat;
				return (true);
			}
		}
	}
	return (false);
}

int	ft_sphere_hit(const void *sphere_obj, const t_ray r, t_hit_rec *rec)
{
	t_sphere	*sp;
	t_equation	quad;
	t_vector3	vhat;
	t_ray		bck_r;
	t_vector3	origin;

	sp = (t_sphere *)sphere_obj;
	bck_r = ft_gtf_apply_ray(sp->tm, r, BCKFORM);
	vhat = ft_vec3_unit(bck_r.lab);
	quad.a = 1;
	quad.b = 2 * ft_vec3_dot(bck_r.p1, vhat);
	quad.c = ft_vec3_dot(bck_r.p1, bck_r.p1) - 1;
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
				rec->p = ft_vec3_add(bck_r.p1, ft_vec3_mult(vhat, quad.t1));
			else
				rec->p = ft_vec3_add(bck_r.p1, ft_vec3_mult(vhat, quad.t2));
			rec->p = ft_gtf_apply_vec3(sp->tm, rec->p, FWDFORM);
			origin = ft_gtf_apply_vec3(sp->tm, ft_vec3_new(0, 0, 0), FWDFORM);
			rec->normal = ft_vec3_unit(ft_vec3_sub(rec->p, origin));
			rec->color = sp->color;
			rec->mat = sp->mat;
		}
		return (true);
	}
	return (false);
}

int	ft_hit_anything(t_objects *list, const t_ray r, t_hit_rec *rec)
{
	t_objects	*tmp_list;
	t_hit_rec	tmp_rec;
	int			hit_anything;
	double		min_dist;

	tmp_list = list;
	hit_anything = false;
	min_dist = 1e6;
	while (tmp_list)
	{
		if (tmp_list->ft_hit(tmp_list->object, r, &tmp_rec))
		{
			if (ft_vec3_len_squared(ft_vec3_sub(tmp_rec.p, r.p1)) < min_dist)
			{
				min_dist = ft_vec3_len_squared(ft_vec3_sub(tmp_rec.p, r.p1));
				hit_anything = true;
				rec->object = tmp_list;
				rec->p = tmp_rec.p;
				rec->normal = tmp_rec.normal;
				rec->color = tmp_rec.color;
				rec->mat = tmp_rec.mat;
			}
		}
		tmp_list = tmp_list->next;
	}
	return (hit_anything);
}
