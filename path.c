/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 10:26:02 by icheres           #+#    #+#             */
/*   Updated: 2016/01/08 18:31:22 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_path_position(char **envp, char *info)
{
	int		index;
	char	*aux;

	index = 0;
	while (envp[index])
	{
		aux = ft_strncpy(aux, envp[index], ft_strlen(info));
		if (ft_strcmp(aux, info) == 0
				&& envp[index][ft_strlen(info)] == '=')
			return (index);
		index++;
	}
	return (0);
}

char	*get_info(char **envp, char *info)
{
	int		index;
	char	*aux;

	index = get_path_position(envp, info);
	aux = (char *)malloc(sizeof(char) * (ft_strlen(envp[index]) + 1));
	aux = ft_strcpy(aux, envp[index]);
	return (aux);
}

void	refresh_path(char **envp)
{
	char	*path;
	char	*home;

	envp[get_path_position(envp, "OLDPWD")] = comp("OLDPWD=", g_oldpath + 1);
	home = envp[get_path_position(envp, "HOME")] + ft_strlen("HOME") + 1;
	path = (char *)malloc(sizeof(char) * PATH_MAX);
	getcwd(path, PATH_MAX);
	envp[get_path_position(envp, "PWD")] = comp("PWD=", path + 14);
}
