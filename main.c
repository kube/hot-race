/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 18:48:58 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/15 22:56:57 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

static t_var		*set_var(unsigned int hash, unsigned int name, char *value)
{
	t_var			*new_var;

	if (!(new_var = (t_var*)malloc(sizeof(t_var))))
		exit(1);
	new_var->hash = hash;
	new_var->name = name;
	new_var->value = ft_strdup(value);
	new_var->next = NULL;
	return (new_var);
}

static t_var		*get_var(unsigned int hash,	unsigned int name, t_var **vars)
{
	t_var			*current;

	if (vars[hash % HASH_MAP_SIZE])
	{
		current = vars[hash % HASH_MAP_SIZE];
		while (current)
		{
			if (current->hash == hash && current->name == name)
				return (current);
			current = current->next;
		}
	}
	return (NULL);
}

static int			index_var(char *name, char *value, t_var **vars)
{
	unsigned int	index;
	unsigned int	name_verif;
	unsigned int	hash;
	t_var			*new_var;

	name_verif = verif_hash(name);
	hash = basic_hash(name);
	if ((new_var = get_var(hash, name_verif, vars)))
	{
		free(new_var->value);
		new_var->value = ft_strdup(value);
		return (0);
	}
	new_var = set_var(hash, name_verif, value);
	index = hash % HASH_MAP_SIZE;
	if (vars[index])
		new_var->next = vars[index];
	vars[index] = new_var;
	return (0);
}

static t_var		**create_var_index()
{
	unsigned int	i;
	t_var			**var_index;

	var_index = (t_var**)malloc(HASH_MAP_SIZE * sizeof(t_var*));
	i = 0;
	while (i < HASH_MAP_SIZE)
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
		if ((searched_var = get_var(basic_hash(read_name),
									verif_hash(read_name), var_index)))
			write(1, searched_var->value, ft_strlen(searched_var->value));
		else
		{
			write(1, read_name, ft_strlen(read_name));
			write(1, ": Not found.", 12);
		}
		write(1, "\n", 1);
	}
	return (0);
}
