/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:46:22 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/14 20:01:47 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//** DESCRIPTION:
//** 		Allocates (with malloc(3)) and returns a string representing the
//**	integer received as an argument. Negative numbers must be handled.

#include <malloc.h>
#include "libft.h"

#include <stdlib.h>

static char	*ft_strrev(char *str, int length)
{
	int	i;
	char temporary;

	i = -1;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}

static int	ft_count_digits(int n)
{
	int	count;

	if (n <= 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int	digits;
	int	negative;
	int	i;

	digits = ft_count_digits(n);
	negative = is_negative(n);
	char *s = (char *) malloc((digits + negative + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (n == -2147483648)
	{
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	if (n < 0)
	{
		n = -n;
		digits--;
	}
	i = 1;
	s[0] = '\0';
	while (i < digits + 1)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (negative)
		s[i] = '-';
	ft_strrev(s, digits + 1 + negative);
	return (s);
}
