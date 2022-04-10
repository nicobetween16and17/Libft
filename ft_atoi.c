/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:37:35 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 13:37:36 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		signe;
	long	res;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-')
			signe = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			res = (10 * res) + (str[i++] - 48);
		if (signe == 1 && res > 2147483647)
			return (-1);
		if (signe == -1 && res > 2147483648)
			return (0);
		while (str[i] != '\0')
			i++;
	}
	return ((int)res * signe);
}
