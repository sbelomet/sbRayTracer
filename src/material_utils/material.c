/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:53:59 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/22 11:41:32 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_material	*ft_mat_new(t_color (*ft_comp_color)
	(t_objects *, t_hit_rec *, t_light *))
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	if (!mat)
		return (NULL);
	mat->ft_comp_color = ft_comp_color;
	mat->reflect = 0;
	mat->shine = 0;
	return (mat);
}