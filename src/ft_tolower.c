/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:13:57 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/12 20:13:57 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by fanny on 01/11/23.
//

#include "libft.h"

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}