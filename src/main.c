/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:38:22 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/08 12:54:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	main(int ac, char **av)
{
	t_base	base;

	if (ft_base_init(&base) == 1)
		on_destroy(&base);
	ft_render(&base);
	ft_hooks(&base);
	(void)ac;
	(void)av;
}
