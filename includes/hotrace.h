/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:15:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/14 05:07:39 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>

#define BUFF_SIZE 1024
#define HASH_MAX_SIZE 16000000
typedef struct		s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}					t_var;
void		ft_putnbr(int n);
size_t		ft_strlen(char *str);
int			ft_strequ(char *str1, char *str2);
char		*ft_strdup(const char *s1);
void		ft_putstr(char *str);
#endif
