/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_implemented_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:45:41 by icheres           #+#    #+#             */
/*   Updated: 2016/03/23 20:56:36 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*unset_env_data(char *data)
{
	char	**array;
	char	*s;

	s = (char *)malloc(sizeof(char));
	s[0] = '=';
	array = ft_split_whitespaces(data, ' ');
	if (array[1])
		return (array[1]);
	else
		return (s);
}
