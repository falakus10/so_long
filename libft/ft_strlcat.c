/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:52 by falakus           #+#    #+#             */
/*   Updated: 2024/10/30 18:53:47 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	dst_long;
	size_t	src_long;

	i = 0;
	src_long = ft_strlen(src);
	dst_long = ft_strlen(dst);
	if (dst_long > dst_size)
		return (dst_size + src_long);
	while (src[i] != '\0' && (dst_long + i + 1 < dst_size))
	{
		dst[dst_long + i] = src[i];
		i++;
	}
	dst[dst_long + i] = '\0';
	return (dst_long + src_long);
}
