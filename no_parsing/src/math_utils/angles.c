/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:22:37 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/09 11:07:32 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

double	ft_deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

double	ft_rad_to_deg(double rad)
{
	return (rad * 180 / M_PI);
}
