/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho-shui <cho-shui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:03:00 by cho-shui          #+#    #+#             */
/*   Updated: 2013/12/13 20:43:42 by cho-shui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFF_SIZE 1024

int	main(void)
{
	char	*read_name;
	char	*read_value;

	read_name = (char*)malloc(BUFF_SIZE * sizeof(char));
	read_value = (char*)malloc(BUFF_SIZE * sizeof(char));
	while (read(1, read_name, BUFF_SIZE) && read_name[0] != '\n')
	{
		read(1, read_value, BUFF_SIZE);
		write(1, "\n", 1);
		write(1, read_name, strlen(read_name) - 1);
		write(1, " = ", 3);
		write(1, read_value, strlen(read_value) - 1);
		write(1, "\n", 1);
	}
	return (0);
}
