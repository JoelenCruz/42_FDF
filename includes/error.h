/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:15:14 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/04/13 10:15:16 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define USG_ERROR "USAGE: ./fdf <file_name_map>.\n"
# define MLX_ERROR "\033[1;31mERROR:\033[1;0m Could not start minilibx.\n"
# define WIN_ERROR "\033[1;31mERROR:\033[1;0m Could not start window.\n"
# define GNL_ERROR "\033[1;31mERROR:\033[1;0m Error while reading from file.\n"
# define MLC_ERROR "\033[1;31mERROR:\033[1;0m Error while allocating memory.\n"
# define IMG_ERROR "\033[1;31mERROR:\033[1;0m Error while creating image.\n"
# define OPN_ERROR "\033[1;31mERROR:\033[1;0m Coud not open file.\n"
# define MAP_ERROR "\033[1;31mERROR:\033[1;0m Invalid map.\n"

#endif
