/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtfm_transforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:35:25 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/21 10:20:36 by sbelomet         ###   ########.fr       */
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
	trans_mtrx.m[0][3] = trans.x;
	trans_mtrx.m[1][3] = trans.y;
	trans_mtrx.m[2][3] = trans.z;
	rot_z_mtrx.m[0][0] = cos(rot.z);
	rot_z_mtrx.m[0][1] = -sin(rot.z);
	rot_z_mtrx.m[1][0] = sin(rot.z);
	rot_z_mtrx.m[1][1] = cos(rot.z);
	rot_y_mtrx.m[0][0] = cos(rot.y);
	rot_y_mtrx.m[0][2] = sin(rot.y);
	rot_y_mtrx.m[2][0] = -sin(rot.y);
	rot_y_mtrx.m[2][2] = cos(rot.y);
	rot_x_mtrx.m[1][1] = cos(rot.x);
	rot_x_mtrx.m[1][2] = -sin(rot.x);
	rot_x_mtrx.m[2][1] = sin(rot.x);
	rot_x_mtrx.m[2][2] = cos(rot.x);
	scale_mtrx.m[0][0] = scale.x;
	scale_mtrx.m[1][1] = scale.y;
	scale_mtrx.m[2][2] = scale.z;
	gt->fwdtfm = ft_mtrx_mult_mtrx(trans_mtrx, ft_mtrx_mult_mtrx(rot_x_mtrx,
				ft_mtrx_mult_mtrx(rot_y_mtrx, ft_mtrx_mult_mtrx(rot_z_mtrx,
						scale_mtrx))));
	gt->bcktfm = ft_mtrx_inverse(gt->fwdtfm);
}

t_vector3	ft_gtf_apply_vec3(const t_gtform gt, const t_vector3 v,
	const int dir_flag)
{
	t_vector4	tmp_vec;

	tmp_vec = ft_vec4_new(v.x, v.y, v.z, 1);
	if (dir_flag)
		tmp_vec = ft_vec4_mult_mtrx(tmp_vec, gt.fwdtfm);
	else
		tmp_vec = ft_vec4_mult_mtrx(tmp_vec, gt.bcktfm);
	return (ft_vec3_new(tmp_vec.x, tmp_vec.y, tmp_vec.z));
}

t_ray	ft_gtf_apply_ray(const t_gtform gt, const t_ray r, const int dir_flag)
{
	t_ray	out_ray;

	out_ray.p1 = ft_gtf_apply_vec3(gt, r.p1, dir_flag);
	out_ray.p2 = ft_gtf_apply_vec3(gt, r.p2, dir_flag);
	out_ray.lab = ft_vec3_sub(out_ray.p2, out_ray.p1);
	return (out_ray);
}
