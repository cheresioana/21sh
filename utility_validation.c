/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 15:59:50 by icheres           #+#    #+#             */
/*   Updated: 2016/03/23 21:00:11 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_only_spaces(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		is_special(char *s)
{
	char	**command;

	if (is_only_spaces(s))
		return (6);
	command = ft_split_whitespaces(s, ' ');
	if (ft_strcmp(command[0], "cd") == 0)
		return (1);
	if (ft_strcmp(command[0], "setenv") == 0)
		return (2);
	if (ft_strcmp(command[0], "unsetenv") == 0)
		return (3);
	if (ft_strcmp(command[0], "env") == 0)
		return (4);
	if (ft_strcmp(command[0], "exit") == 0)
		return (-1);
	return (0);
}

int		arg_number(char **data)
{
	int		index;

	index = 0;
	while (data[index])
		index++;
	return (index);
}

int		exists(char *s, char c)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}
