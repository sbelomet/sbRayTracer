/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:08:51 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/08 15:20:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

void	ft_pixel_put(t_base *base, int x, int y, int color)
{
	int	pos;

	pos = (x * base->image.bitsperpix / 8) + (y * base->image.size_line);
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(int *) &base->image.img_data[pos] = color;
}

void	ft_render(t_base *base)
{
	int		index[2];
	t_color	c;

	index[1] = -1;
	while (++index[1] < WIN_HEIGHT)
	{
		index[0] = -1;
		printf("Scanlines remaining: %d\n", WIN_HEIGHT - index[1]);
		while (++index[0] < WIN_WIDTH)
		{
			c = ft_color_new(0, (double)index[0] / (WIN_WIDTH - 1),
					(double)index[1] / (WIN_HEIGHT - 1), 0);
			ft_pixel_put(base, index[0], index[1], ft_get_color_int(c));
		}
		mlx_put_image_to_window(base->mlx_ptr, base->win_ptr,
			base->image.img_ptr, 0, 0);
	}
}
