/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:31 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:14:32 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	ft_nbtrim(char const *s1, char const *set)
{
	int	i;
	int	max;

	max = ft_strlen(s1);
	i = 0;
	while (ft_is_set(*s1++, set) && *s1)
		i++;
	if (i < max)
	{
		while (ft_is_set(s1[--max], set))
			i++;
	}
	return (i);
}

int	ft_nbbacktrim(char const *s1, char const *set)
{
	int res;

	res = 0;
	s1 += ft_strlen(s1) - 1;
	while (ft_is_set(*s1, set) && (size_t)res <= ft_strlen(s1))
		res++;
	return (ft_strlen(s1) - res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;

	i = ft_nbtrim(s1, set);
	trim = malloc(sizeof(char) * (ft_strlen(s1) - i));
	if (!trim)
		return (0);
	while (*s1 && ft_is_set(*s1, set))
		s1++;
	i = 0;
	while (*s1 && i < ft_nbbacktrim(s1, set))
		trim[i++] = *s1++;
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int main()
{
	printf("%lu\n", (ft_strlen(s1) - i + 1));
	printf("%s\n", ft_strtrim("   xxxtripouille", " x"));
}*/
