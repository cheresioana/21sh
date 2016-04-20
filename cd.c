/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:35:59 by icheres           #+#    #+#             */
/*   Updated: 2016/01/06 14:49:50 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_homedir(char *data, char **envp)
{
	char			*home;
	char			**files;
	DIR				*dir;
	char			*pwd;

	files = NULL;
	pwd = get_info(envp, "PWD") + ft_strlen("PWD") + 1;
	files = ft_split_whitespaces(data, ' ');
	home = (data && files[1][0] == '/') ? ("/") :
		(get_info(envp, "HOME") + ft_strlen("HOME") + 1);
	dir = opendir(home);
	chdir(home);
	if (data && files[1][0] == '~')
		files[1]++;
	if (data)
		files = ft_split_whitespaces(files[1], '/');
	if (files)
		if (recursive_search(files, 0, arg_number(files), dir) == 2)
		{
			closedir(dir);
			dir = opendir(pwd);
			chdir(pwd);
		}
	return (1);
}

int		recursive_search(char **d, int i, int max, DIR *dir)
{
	t_st			s;
	DIR				*dir2;
	int				fd;

	while (i < max)
	{
		s.dp = readdir(dir);
		if (s.dp == NULL)
			return (r_msj_val("cd: no such file or directory: ", d[i], 2));
		if (ft_strcmp(d[i], s.dp->d_name) == 0)
		{
			fd = open(s.dp->d_name, O_RDONLY);
			if (fstat(fd, &s.stat) < 0)
				return (r_msj_val("cd: permission denied: ", d[i], 2));
			if (!S_ISDIR(s.stat.st_mode))
				return (r_msj_val("cd: not a directory: ", d[i], 2));
			dir2 = opendir(d[i]);
			closedir(dir);
			chdir(d[i]);
			return (recursive_search(d, i + 1, max, dir2));
		}
	}
	return (1);
}

int		ft_cd(char *data, char **envp)
{
	char			**mat;
	char			**files;
	DIR				*dir;

	mat = ft_split_whitespaces(data, ' ');
	if (arg_number(mat) > 2)
		return_msj_val("Invalid input for \"cd\"", 1);
	if (mat[1] && mat[1][0] == '-' && !mat[1][1])
	{
		chdir(g_oldpath);
		return (r_msj_val("~",
					minus(g_oldpath, get_info(envp, "HOME") + 5), 1));
	}
	else
		g_oldpath = get_info(envp, "PWD") + ft_strlen("PWD") + 1;
	if (arg_number(mat) == 1)
		return (find_homedir(NULL, envp));
	if (mat[1][0] == '/' || mat[1][0] == '~')
		return (find_homedir(data, envp));
	files = ft_split_whitespaces(mat[1], '/');
	dir = opendir(".");
	return (recursive_search(files, 0, arg_number(files), dir));
}
