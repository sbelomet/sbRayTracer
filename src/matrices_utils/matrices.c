/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:33:44 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/14 14:40:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_matrix	ft_mtr_new(void)
{
	t_matrix	m;

	m.c1 = ft_vec4_new(1, 0, 0, 0);
	m.c2 = ft_vec4_new(0, 1, 0, 0);
	m.c3 = ft_vec4_new(0, 0, 1, 0);
	m.c4 = ft_vec4_new(0, 0, 0, 1);
	return (m);
}

t_matrix	ft_mtrx_new2(const t_vector4 x, const t_vector4 y,
	const t_vector4 z, const t_vector4 w)
{
	t_matrix	m;

	m.c1 = x;
	m.c2 = y;
	m.c3 = z;
	m.c4 = w;
	return (m);
}

void	ft_mtrx_print(const t_matrix m, const char *name)
{
	printf("Matrix %s:\n", name);
	printf("[%f][%f][%f][%f]\n", m.c1.x, m.c1.y, m.c1.z, m.c1.w);
	printf("[%f][%f][%f][%f]\n", m.c2.x, m.c2.y, m.c2.z, m.c2.w);
	printf("[%f][%f][%f][%f]\n", m.c3.x, m.c3.y, m.c3.z, m.c3.w);
	printf("[%f][%f][%f][%f]\n", m.c4.x, m.c4.y, m.c4.z, m.c4.w);
}
