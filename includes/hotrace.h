/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:15:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 22:54:30 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# include <get_next_line.h>

#define HASH_MAP_SIZE 16000000

typedef struct		s_var
{
	unsigned int	hash;
	unsigned int	name;
	char			*value;
	struct s_var	*next;
}					t_var;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putnbr(int n);
size_t				ft_strlen(char *str);
int					ft_strequ(char *str1, char *str2);
char				*ft_strdup(const char *s1);
void				ft_putstr(char *str);

unsigned int		basic_hash(char *str);
unsigned int		verif_hash(char *str);

void				ft_lstqueueadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
#endif
