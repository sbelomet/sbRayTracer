/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:03:35 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/14 15:32:00 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

static t_matrix	ft_mult_cont(t_matrix m, const t_matrix m1,
	const t_matrix m2)
{
	m.c1.z = m1.c1.z * m2.c1.x + m1.c2.z * m2.c1.y
		+ m1.c3.z * m2.c1.z + m1.c4.z * m2.c1.w;
	m.c2.z = m1.c1.z * m2.c2.x + m1.c2.z * m2.c2.y
		+ m1.c3.z * m2.c2.z + m1.c4.z * m2.c2.w;
	m.c3.z = m1.c1.z * m2.c3.x + m1.c2.z * m2.c3.y
		+ m1.c3.z * m2.c3.z + m1.c4.z * m2.c3.w;
	m.c4.z = m1.c1.z * m2.c4.x + m1.c2.z * m2.c4.y
		+ m1.c3.z * m2.c4.z + m1.c4.z * m2.c4.w;
	m.c1.w = m1.c1.w * m2.c1.x + m1.c2.w * m2.c1.y
		+ m1.c3.w * m2.c1.z + m1.c4.w * m2.c1.w;
	m.c2.w = m1.c1.w * m2.c2.x + m1.c2.w * m2.c2.y
		+ m1.c3.w * m2.c2.z + m1.c4.w * m2.c2.w;
	m.c3.w = m1.c1.w * m2.c3.x + m1.c2.w * m2.c3.y
		+ m1.c3.w * m2.c3.z + m1.c4.w * m2.c3.w;
	m.c4.w = m1.c1.w * m2.c4.x + m1.c2.w * m2.c4.y
		+ m1.c3.w * m2.c4.z + m1.c4.w * m2.c4.w;
	return (m);
}

t_matrix	ft_mtrx_mult_mtrx(const t_matrix m1, const t_matrix m2)
{
	t_matrix	m;

	m.c1.x = m1.c1.x * m2.c1.x + m1.c2.x * m2.c1.y
		+ m1.c3.x * m2.c1.z + m1.c4.x * m2.c1.w;
	m.c2.x = m1.c1.x * m2.c2.x + m1.c2.x * m2.c2.y
		+ m1.c3.x * m2.c2.z + m1.c4.x * m2.c2.w;
	m.c3.x = m1.c1.x * m2.c3.x + m1.c2.x * m2.c3.y
		+ m1.c3.x * m2.c3.z + m1.c4.x * m2.c3.w;
	m.c4.x = m1.c1.x * m2.c4.x + m1.c2.x * m2.c4.y
		+ m1.c3.x * m2.c4.z + m1.c4.x * m2.c4.w;
	m.c1.y = m1.c1.y * m2.c1.x + m1.c2.y * m2.c1.y
		+ m1.c3.y * m2.c1.z + m1.c4.y * m2.c1.w;
	m.c2.y = m1.c1.y * m2.c2.x + m1.c2.y * m2.c2.y
		+ m1.c3.y * m2.c2.z + m1.c4.y * m2.c2.w;
	m.c3.y = m1.c1.y * m2.c3.x + m1.c2.y * m2.c3.y
		+ m1.c3.y * m2.c3.z + m1.c4.y * m2.c3.w;
	m.c4.y = m1.c1.y * m2.c4.x + m1.c2.y * m2.c4.y
		+ m1.c3.y * m2.c4.z + m1.c4.y * m2.c4.w;
	return (ft_mult_cont(m, m1, m2));
}
