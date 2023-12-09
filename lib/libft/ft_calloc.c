/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:03:35 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/15 16:11:39 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (size && count > 2147483647 / size)
		return (0);
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, total);
	return (ptr);
}
