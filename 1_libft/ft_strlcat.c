/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:31:37 by jhur              #+#    #+#             */
/*   Updated: 2020/04/15 18:33:44 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dest_len;
	size_t	src_len;

	idx = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len <= dstsize)
		src_len += dest_len;
	else
		src_len += dstsize;
	while (src[idx] != '\0' && dest_len + 1 < dstsize)
	{
		dst[dest_len] = src[idx];
		dest_len++;
		idx++;
	}
	dst[dest_len] = '\0';
	return (src_len);
}
