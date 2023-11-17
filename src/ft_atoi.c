/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:46:22 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/13 01:40:59 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void ft_whitespace(const char *string)
{
    while (*string == ' ' || *string == '\n' || *string == '\t'
           || *string == '\v' || *string == '\r' || *string == '\f')
        string++;
}

int ft_sign(const char *string)
{
    int sign;

    sign = 1;
    if (*string == '-' || *string == '+')
    {
        if (*string == '-')
            sign *= -1;
    }
    return (sign);
}

int ft_atoi(const char *string)
{
    long res;
    int i;
    int sign;

	sign = ft_sign(string);
    i = 0;
	res = 0;
    if (ft_sign(string) < 0)
		i++;
    while (string[i] >= '0' && string[i] <= '9')
    {
        if (res != ((res * 10 - string[i] + '0') / 10))
            return (-1 * (sign > 0));
		res = res * 10 + (string[i] - '0');
        i++;
    }
    return (int)(res * sign);
}
