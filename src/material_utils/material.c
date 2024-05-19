/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:53:59 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/19 13:51:26 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_material	*ft_mat_new(t_color (*ft_comp_color)
	(t_objects *, t_hit_rec *, t_light *))
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	mat->ft_comp_color = ft_comp_color;
	mat->reflect = 0;
	mat->shine = 0;
	return (mat);
}