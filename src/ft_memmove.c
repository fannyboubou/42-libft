/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:46:22 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/11 08:46:22 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memmove() function shall copy n bytes from the object pointed
//	to by s2 into the object pointed to by s1.  Copying takes place
//	as if the n bytes from the object pointed to by s2 are first
//copied into a temporary array of n bytes that does not overlap
//the objects pointed to by s1 and s2, and then the n bytes from
//	the temporary array are copied into the object pointed to by s1.

#include <stdio.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	char *byte_src;
	char *byte_dest;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	byte_src = (char *) src;
	byte_dest = (char *) dest;

	if ((size_t) dest - (size_t) src < n)
	{
		i = n - 1;
		while (i < n)
		{
			byte_dest[i] = byte_src[i];
			i--;
		}
	} else
	{
		while (i < n)
		{
			byte_dest[i] = byte_src[i];
			i++;
		}
	}
	return ((void *) byte_dest);
}