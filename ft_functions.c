/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 00:38:40 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/14 00:41:39 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

void		ft_putnbr(int n)
{
	char	a;

	if (n < 0)
		write(1, "-", 1);
	if (n / 10)
		ft_putnbr(ft_abs(n / 10));
	a = '0' + ft_abs(n % 10);
	write(1, &a, 1);
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
