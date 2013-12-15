/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 00:38:40 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 01:48:42 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s1)
		return (0);
	s2 = (char*)malloc(ft_strlen((char*)s1) * sizeof(*s1));
	if (s2)
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
	}
	else
		return (0);
	return (s2);
}

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int			ft_strequ(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
