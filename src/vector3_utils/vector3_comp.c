/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:23:37 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/08 15:36:26 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_vec3_grtr(const t_vector3 v1, const t_vector3 v2)
{
	if (v1.x > v2.x && v1.y > v2.y && v1.z > v2.z)
		return (true);
	return (false);
}

int	ft_vec3_lssr(const t_vector3 v1, const t_vector3 v2)
{
	if (v1.x < v2.x && v1.y < v2.y && v1.z < v2.z)
		return (true);
	return (false);
}
