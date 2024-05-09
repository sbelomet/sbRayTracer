/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:15:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/09 15:46:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_compute_light(t_objects *list, t_objects *current, t_hit_rec *rec, t_color c)
{
	t_vector3	light_dir;

	light_dir = ft_vec3_unit(ft_vec3_sub());
}
