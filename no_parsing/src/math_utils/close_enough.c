/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_enough.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:08:17 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/09 11:10:09 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

int	ft_close_enough(const double f1, const double f2)
{
	if (fabs(f1 - f2) < 1e-21)
		return (true);
	return (false);
}
