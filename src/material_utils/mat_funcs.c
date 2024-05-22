/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:42:15 by scherty           #+#    #+#             */
/*   Updated: 2024/05/22 11:07:08 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_color	ft_comp_diffuse_color(t_objects *list, t_hit_rec *rec, t_light *lights)
{
	t_color	diffuse;

	diffuse = ft_color_new(0, 0, 0, 0);
	ft_calc_lights(list, rec, lights);
	rec->emmited = ft_color_add(rec->emmited, ft_color_mult(
				rec->base->alight->color, rec->base->alight->ratio));
	diffuse = ft_color_mult_color(rec->emmited, rec->color);
	return (diffuse);
}

/* 
t_color	ft_comp_spec_color(t_objects *list, t_hit_rec *rec, t_light *lights)
{
	t_color	spec;

	spec = ft_color_new(0, 0, 0, 0);
	
} */