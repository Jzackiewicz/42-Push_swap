/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:32:57 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 16:53:49 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	while (src[i] != 0)
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}
