/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho-shui <cho-shui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:03:00 by cho-shui          #+#    #+#             */
/*   Updated: 2013/12/14 05:22:27 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

static unsigned int	basic_hash(char *str)
{
	size_t			i;
	size_t			str_block_size;
	unsigned int	*current_block;
	unsigned int	hash_result;

	str_block_size = ft_strlen(str) / sizeof(int);
	i = 0;
	hash_result = 0;
	current_block = (unsigned int*)str;
	while (i < str_block_size)
	{
		hash_result += current_block[i];
		i++;
	}
	hash_result = hash_result % HASH_MAX_SIZE;
	return (hash_result);
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

	if ((new_var = get_var(name, var_index)))
	{
		free(new_var->value);
		new_var->value = ft_strdup(value);
		return (0);
	}
	new_var = set_var(ft_strdup(name), ft_strdup(value));
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

	// DUPLICATE STRING !!!!!!!!!!!

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
	int				ret;

	var_index = create_var_index();
	read_name = (char*)malloc(BUFF_SIZE * sizeof(char));
	read_value = (char*)malloc(BUFF_SIZE * sizeof(char));
	while ((ret = read(1, read_name, BUFF_SIZE)) && ret > 0)
	{
		read_name[ret] = 0;
		ft_putnbr(basic_hash(read_name));
		ret = read(1, read_value, BUFF_SIZE);
		read_value[ret] = 0;
		index_var(read_name, read_value, var_index);
	}
	while ((ret = read(1, read_name, BUFF_SIZE)) && ret > 0)
	{
		read_name[ret] = 0;
		ft_putnbr(basic_hash(read_name));
		if ((searched_var = get_var(read_name, var_index)))
			ft_putstr(searched_var->value);
		else
			ft_putstr("\x1B[31mNot found.\x1B[0m");
		ft_putstr("\n");
	}
	return (0);
}
