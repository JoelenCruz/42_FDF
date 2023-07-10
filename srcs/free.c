/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:44:56 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/05/14 12:15:01 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This function frees ervery data allocated in a t_fdf struct.
 * 
 * @param fdf The t_fdf to be freed.
 */

static void	free_fdf(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (fdf->points[y])
	{
		x = 0;
		while (fdf->points[y][x])
		{
			free(fdf->points[y][x]);
			x++;
		}
		free(fdf->points[y]);
		y++;
	}
	free(fdf->points);
}

void	free_all(t_win *data)
{
	free(data->fdf->controls);
	free_fdf(data->fdf);
}

void	print_error(char *error_msg, char *path)
{
	ft_printf(error_msg);
	free(path);
	exit(1);
}

// void	print_error(char *error_msg)
// {
// 	ft_printf(error_msg);
// 	exit(1);
// }

int	end_program(t_win *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->legend.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->fdf->controls);
	free_fdf(data->fdf);
	free(data->fdf);
	free(data);
	exit(0);
}
