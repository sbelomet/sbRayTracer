/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:07:41 by lgosselk          #+#    #+#             */
/*   Updated: 2024/05/09 19:54:58 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

void	on_destroy(t_base *base)
{
	if (base->win_ptr)
		mlx_destroy_window(base->mlx_ptr, base->win_ptr);
	if (base->mlx_ptr)
		free(base->mlx_ptr);
	ft_malloc_clear(&base->alloc);
	exit(base->exit_code);
}

int	close_window(t_base *base)
{
	on_destroy(base);
	return (0);
}
