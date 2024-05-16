/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:38:22 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/16 15:26:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	main(int ac, char **av)
{
	t_base		base;
	t_gtform	gt;

	if (ft_base_init(&base) == 1)
		on_destroy(&base);
	//ft_render(&base);
	//ft_hooks(&base);
	gt = ft_gtf_new();
	ft_gtf_set_transform(&gt, ft_vec3_new(23.4, 25, 0), ft_vec3_new(2.56, 1, 2.467), ft_vec3_new(1, 1, 1.3));
	(void)ac;
	(void)av;
}
