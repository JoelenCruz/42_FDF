/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:13:57 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/04/15 13:14:01 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!n)
		return (0);
	while (*(unsigned char *)str1++ == *(unsigned char *)str2++ && --n)
		;
	return (*(unsigned char *)(--str1) - *(unsigned char *)(--str2));
}
