/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:48:17 by sbelomet          #+#    #+#             */
/*   Updated: 2024/05/14 14:40:07 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_gtform	ft_gtf_new(void)
{
	t_gtform	gt;

	gt.fwdtfm = ft_mtrx_new();
	gt.bcktfm = ft_mtrx_new();
	return (gt);
}

t_gtform	ft_gtf_new2(const t_matrix fwd, const t_matrix bck)
{
	t_gtform	gt;

	gt.fwdtfm = fwd;
	gt.bcktfm = bck;
	return (gt);
}
