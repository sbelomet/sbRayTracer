/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtfm_transforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:35:25 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/14 15:54:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

void	ft_gtf_set_transform(t_gtform *gt, const t_vector3 trans,
	const t_vector3 rot, const t_vector3 scale)
{
	t_matrix	trans_mtrx;
	t_matrix	rot_x_mtrx;
	t_matrix	rot_y_mtrx;
	t_matrix	rot_z_mtrx;
	t_matrix	scale_mtrx;

	trans_mtrx = ft_mtrx_new();
	rot_x_mtrx = ft_mtrx_new();
	rot_y_mtrx = ft_mtrx_new();
	rot_z_mtrx = ft_mtrx_new();
	scale_mtrx = ft_mtrx_new();
	trans_mtrx.c4.x = trans.x;
	trans_mtrx.c4.y = trans.y;
	trans_mtrx.c4.z = trans.z;
	rot_z_mtrx.c1.x = cos(rot.z);
	rot_z_mtrx.c2.x = -sin(rot.z);
	rot_z_mtrx.c1.y = sin(rot.z);
	rot_z_mtrx.c2.x = cos(rot.z);
	rot_y_mtrx.c1.x = cos(rot.y);
	rot_y_mtrx.c3.x = sin(rot.y);
	rot_y_mtrx.c1.z = -sin(rot.y);
	rot_y_mtrx.c3.z = cos(rot.y);
	rot_x_mtrx.c2.y = cos(rot.x);
	rot_x_mtrx.c3.y = -sin(rot.x);
	rot_x_mtrx.c2.z = sin(rot.x);
	rot_x_mtrx.c3.z = cos(rot.x);
	scale_mtrx.c1.x = scale.x;
	scale_mtrx.c2.y = scale.y;
	scale_mtrx.c3.z = scale.z;
	gt->fwdtfm = ft_mtrx_mult_mtrx(trans_mtrx, ft_mtrx_mult_mtrx(scale_mtrx,
				ft_mtrx_mult_mtrx(rot_x_mtrx, ft_mtrx_mult_mtrx(rot_y_mtrx,
						rot_z_mtrx))));
}
