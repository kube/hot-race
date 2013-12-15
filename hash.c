/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:30:01 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 23:26:33 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

unsigned int		basic_hash(char *str)
{
	int				c;
	unsigned int	hash;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

unsigned int		verif_hash(char *str)
{
	int				c;
	unsigned int	hash;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 3);
	return (hash);
}
