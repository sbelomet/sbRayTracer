/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:15:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/14 11:01:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_compute_light(t_objects *list, t_objects *current, t_hit_rec *rec, t_light *l)
{
	t_vector3	light_dir;
//	t_vector3	start_point;
	double		angle;

	(void)list;
	(void)current;
	light_dir = ft_vec3_unit(ft_vec3_sub(l->coord, rec->p));
	//ft_vec3_print(light_dir, "coord");
//	start_point = rec->p;
	angle = acos(ft_vec3_dot(rec->normal, light_dir));
	if (angle > 1.5708)
	{
		//ft_vec3_print(rec->normal, "away: normal");
		rec->color = l->color;
		rec->intensity = 0.0;
		return (false);
	}
	else
	{
		//ft_vec3_print(rec->normal, "to: normal");
		rec->color = l->color;
		rec->intensity = l->ratio * (1 - (angle / 1.5708));
		return (true);
	}
}

int	ft_calc_lights(t_objects *list, t_objects *current, t_hit_rec *rec, t_light *lights)
{
	t_light		*tmp_light;
	t_hit_rec	tmp_rec;
	int			light_good;

	tmp_light = lights;
	light_good = false;
	while (tmp_light)
	{
		if (ft_compute_light(list, current, &tmp_rec, tmp_light))
		{
			light_good = true;
			rec->color = tmp_rec.color;
			rec->intensity = tmp_rec.intensity;
		}
		tmp_light = tmp_light->next;
	}
	return (light_good);
}
