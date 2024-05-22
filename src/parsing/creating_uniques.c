/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_uniques.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:08:42 by lgosselk          #+#    #+#             */
/*   Updated: 2024/05/22 13:31:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sbrt.h"

t_light	*create_light(char **args)
{
	t_light		*light;

	light = (t_light *) malloc (sizeof(t_light));
	if (!light)
		return (print_error_null("Error\n", MALLOC_ERR));
	light->coord = parse_vector(args[0]);
	light->ratio = ft_atof(args[1]);
	if (out_range(0, 1, light->ratio))
		return (free(light), print_error_null("Error\n", RANGE_ERR));
	light->color = parse_color(args[2]);
	if (out_range_color(light->color))
		return (free(light), print_error_null("Error\n", RANGE_ERR));
	return (light);
}

t_camera	*create_camera(char **args)
{
	t_camera	*camera;

	camera = (t_camera *) malloc (sizeof(t_camera));
	if (!camera)
		return (print_error_null("Error\n", MALLOC_ERR));
	camera->lookfrom = parse_vector(args[0]);
	printf("args 0: %s\n", args[0]);
	ft_vec3_print(camera->lookfrom, "cam pos");
	camera->lookat = parse_vector(args[1]);
	printf("args 1: %s\n", args[1]);
	ft_vec3_print(camera->lookat, "cam target");
	if (out_range_norm(camera->lookat))
		return (free(camera), print_error_null("Error\n", RANGE_ERR));
	camera->horz_size = (double)ft_atoi(args[2]) / 90;
	if (camera->horz_size < 0 || camera->horz_size > 2)
		return (free(camera), print_error_null("Error\n", RANGE_ERR));
	printf("horz: %f\n", camera->horz_size);
	ft_update_cam(camera);
	printf("camera created\n");
	return (camera);
}

t_alight	*create_amblight(char **args)
{
	t_alight	*amblight;

	amblight = (t_alight *) malloc(sizeof(t_alight));
	if (!amblight)
		return (print_error_null("Error\n", MALLOC_ERR));
	amblight->ratio = ft_atof(args[0]);
	if (out_range(0, 1, amblight->ratio))
		return (free(amblight), print_error_null("Error\n", RANGE_ERR));
	amblight->color = parse_color(args[1]);
	if (out_range_color(amblight->color))
		return (free(amblight), print_error_null("Error\n", RANGE_ERR));
	amblight->color = ft_color_byte_to_per(amblight->color);
	return (amblight);
}
