/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 18:48:58 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 02:38:10 by cfeijoo          ###   ########.fr       */
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
	return (hash % HASH_MAX_SIZE);
}

static t_var		*set_var(char *name, char *value)
{
	t_var			*new_var;

	if (!(new_var = (t_var*)malloc(sizeof(t_var))))
		exit(1);
	new_var->name = name;
	new_var->value = value;
	new_var->next = NULL;
	return (new_var);
}

static t_var		*get_var(char *name, t_var **var_index)
{
	int				hash;
	t_var			*current;

	hash = basic_hash(name);
	if (var_index[hash])
	{
		current = var_index[hash];
		while (current)
		{
			if (ft_strequ(current->name, name))
				return (current);
			current = current->next;
		}
	}
	return (NULL);
}

static int			index_var(char *name, char *value, t_var **var_index)
{
	int				hash;
	t_var			*new_var;

	name = ft_strdup(name);
	if ((new_var = get_var(name, var_index)))
	{
		free(new_var->value);
		new_var->value = ft_strdup(value);
		return (0);
	}
	new_var = set_var(name, ft_strdup(value));
	hash = basic_hash(name);
	if (var_index[hash])
		new_var->next = var_index[hash];
	var_index[hash] = new_var;
	return (0);
}

static t_var		**create_var_index()
{
	unsigned int	i;
	t_var			**var_index;

	var_index = (t_var**)malloc(HASH_MAX_SIZE * sizeof(t_var*));
	i = 0;
	while (i < HASH_MAX_SIZE)
	{
		var_index[i] = NULL;
		i++;
	}
	return (var_index);
}

int					main(void)
{
	t_var			**var_index;
	char			*read_name;
	char			*read_value;
	t_var			*searched_var;

	var_index = create_var_index();
	while (get_next_line(0, &read_name) > 0 && *read_name)
	{
		get_next_line(0, &read_value);
		index_var(read_name, read_value, var_index);
	}
	while (get_next_line(0, &read_name) > 0 && *read_name)
	{
		if ((searched_var = get_var(read_name, var_index)))
		{
			ft_putstr(searched_var->value);
		}
		else
		{
			ft_putstr(read_name);
			ft_putstr(": Not found.");
		}
		ft_putstr("\n");
	}
	return (0);
}
