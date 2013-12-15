/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:15:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 23:35:17 by cfeijoo          ###   ########.fr       */
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

unsigned int		basic_hash(char *str);
unsigned int		verif_hash(char *str);
size_t				ft_strlen(char *str);
char				*ft_strdup(const char *s1);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstqueueadd(t_list **alst, t_list *new);
#endif
