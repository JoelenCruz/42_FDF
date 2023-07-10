/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:42:32 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/04/15 15:42:36 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Set the zoom object
 * 
 * @param button The button pressed.
 * @param data The data object.
 */
static void	set_zoom(int button, t_win *data)
{
	if (button == 4)
		data->fdf->controls->zoom *= 1.2;
	if (button == 5)
		data->fdf->controls->zoom /= 1.2;
	if (data->fdf->controls->zoom < 1)
		data->fdf->controls->zoom = 1;
	reproject(data);
}

/**
 * @brief Set the position object
 * 
 * @param x The position on the x axys.
 * @param y The position on the y axys.
 * @param data The data object.
 * @return int 1
 */
static int	set_position(int x, int y, t_win *data)
{
	data->fdf->controls->shift_x = x;
	data->fdf->controls->shift_y = y;
	reproject(data);
	return (1);
}

int	press_mouse(int button, int x, int y, t_win *data)
{
	if (button == 4 || button == 5)
		set_zoom(button, data);
	else if (button == 1)
		set_position(x, y, data);
	return (1);
}
