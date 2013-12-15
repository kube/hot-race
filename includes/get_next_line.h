/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 02:14:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 23:37:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 128000

int					get_next_line(char **line);

typedef struct		s_read
{
	int				size;
	int				index;
	char			*read;
	struct s_read	*next;
}					t_read;

#endif /* !GET_NEXT_LINE_H */
