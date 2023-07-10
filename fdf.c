/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:01:36 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/04/13 10:01:48 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_win *data)
{
	render_background(&data->img, C_NIER_BG);
	draw_legend(data);
	rotate(data->fdf);
	projection(data->fdf);
	plot_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
							L_WIDTH, L_HEIGHT);
	return (1);
}

void	print_points(t_fdf *fdf)
{
	int	i;
	int	x;

	i = 0;
	while (fdf->points[i])
	{
		x = 0;
		while (fdf->points[i][x])
		{
			ft_printf("%d ", fdf->points[i][x]->pz);
			x++;
		}
		i++;
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	char	*path;
	t_win	*data;
	char	*file_name;
	int		fd;

	path = ft_calloc(50, sizeof(char));
	if (argc != 2)
		print_error(USG_ERROR, path);
	file_name = argv[1];
	ft_strlcat(path, file_name, 50);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error(USG_ERROR, path);
	data = (t_win *)malloc(sizeof (t_win));
	init_mlx(data, path);
	read_input(data->fdf, path);
	mlx_expose_hook(data->win_ptr, expose_hook, data);
	mlx_key_hook(data->win_ptr, press_key, data);
	mlx_mouse_hook(data->win_ptr, press_mouse, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, end_program, data);
	free(path);
	mlx_loop(data->mlx_ptr);
	return (0);
}
