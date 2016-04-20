/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implemented_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:06:19 by icheres           #+#    #+#             */
/*   Updated: 2016/03/23 20:56:20 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char *data, char **env)
{
	int		index;
	char	*aux;
	int		size;

	index = 0;
	if (exists(data, '='))
	{
		ft_putstr("Invalid format, give only the name of the variable\n");
		return (env);
	}
	data = unset_env_data(data);
	size = ft_strlen(data);
	aux = (char *)malloc(sizeof(char) * size);
	while (env[index])
	{
		if (env[index][size])
		{
			aux = ft_strncpy(aux, env[index], size);
			if ((ft_strcmp(aux, data) == 0) && (env[index][size] == '='))
				return (del_from_matrix(env, index));
		}
		index++;
	}
	free(aux);
	return (env);
}

char	**ft_setenv(char *s, char **env)
{
	char	**data;
	char	**new_env;
	int		i;
	char	*valid_data;

	i = 0;
	data = ft_split_whitespaces(s, ' ');
	if (arg_number(data) != 3 || s == NULL || exists(s, '='))
	{
		ft_putstr("Invalid input\nSugested input:setenv\tNAME\tVALUE\n");
		return (env);
	}
	new_env = (char **)malloc(sizeof(char *) * (arg_number(env) + 3));
	i = 0;
	while (env[i])
	{
		new_env[i] = (char *)malloc(sizeof(char) * (ft_strlen(env[i])));
		new_env[i] = ft_strcpy(new_env[i], env[i]);
		i++;
	}
	valid_data = concat_with(data, '=');
	new_env[i] = (char *)malloc(sizeof(char) * (ft_strlen(valid_data)));
	new_env[i] = ft_strcpy(new_env[i], valid_data);
	new_env[i + 1] = NULL;
	return (new_env);
}

int		ft_implement_functions(char *data, char ***env)
{
	int		command;
	int		index;

	index = 0;
	command = is_special(data);
	if (command == -1)
		return (-1);
	if (command == 4)
		return (print_env(*env));
	if (command == 2)
		*env = ft_setenv(data, *env);
	if (command == 3)
		*env = ft_unsetenv(data, *env);
	if (command == 1)
		return (ft_cd(data, *env));
	return (1);
}
