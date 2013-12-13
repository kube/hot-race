/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho-shui <cho-shui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:03:00 by cho-shui          #+#    #+#             */
/*   Updated: 2013/12/14 00:46:48 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

static unsigned int	basic_hash(char *str)
{
	size_t			i;
	size_t			str_block_size;
	unsigned int	*current_block;
	unsigned int	hash_result;

	str_block_size = ft_strlen(str) / sizeof(int) + 1;
	i = 0;
	hash_result = 0;
	current_block = (unsigned int*)str;
	while (i < str_block_size)
	{
		hash_result += current_block[i];
		i++;
	}
	/*hash_result = hash_result % HASH_MAX_SIZE;*/
	hash_result = hash_result;
	return (hash_result);
}

static t_var		*set_var(char *name, char *value, t_var **var_index)
{
	t_var			*new_var;

	if ((new_var = (t_var*)malloc(sizeof(t_var))))
	{
		write(2, "Error during var allocation.\n", ft_strlen("Error during var allocation.\n"));
		exit(1);
	}
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
		new_var->value = value;
		return (0);
	}
	new_var = set_var(name, value, var_index);
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

	var_index = create_var_index();
	read_name = (char*)malloc(BUFF_SIZE * sizeof(char));
	read_value = (char*)malloc(BUFF_SIZE * sizeof(char));
	while (read(1, read_name, BUFF_SIZE) && read_name[0] != '\n')
	{
		read(1, read_value, BUFF_SIZE);
		write(1, "\n", 1);
		read_name[ft_strlen(read_name) - 1] = 0;
		read_value[ft_strlen(read_value) - 1] = 0;
		write(1, read_name, ft_strlen(read_name));
		write(1, " = ", 3);
		write(1, read_value, ft_strlen(read_value));
		write(1, "\nBASIC HASH : ", 14);
		ft_putnbr(basic_hash(read_name));
		write(1, "\n", 1);
	}
	return (0);
}
