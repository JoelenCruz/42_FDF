/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:11:53 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/04/22 16:11:56 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str++ == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
