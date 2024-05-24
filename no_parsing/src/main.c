/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:38:22 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/18 15:10:52 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	main(int ac, char **av)
{
	t_base		base;

	if (ft_base_init(&base) == 1)
		on_destroy(&base);
	ft_render(&base);
	ft_hooks(&base);
	(void)ac;
	(void)av;
}
