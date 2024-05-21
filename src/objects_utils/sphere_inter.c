/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:35:50 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/21 13:36:19 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

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
