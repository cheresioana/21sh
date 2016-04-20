/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 10:15:11 by icheres           #+#    #+#             */
/*   Updated: 2016/04/20 12:54:30 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_p2(int argc, char **argv, char ***paths, char **envp)
{
	(void)(argc);
	(void)(argv);
	envp[get_path_position(envp, "_")] = comp("_=", "usr/bin/env");
	g_oldpath = (char *)malloc(sizeof(char) * (PATH_MAX));
	g_oldpath = get_info(envp, "OLDPWD") + 7;
	*paths = ft_split_whitespaces(get_info(envp, "PATH"), ':');
	*paths[0] = *paths[0] + 5;
}

void	main_p3(t_ok *k, int *count, char **i_d)
{
	k->ok2 = 1;
	*count = 0;
	write(1, "$>", 2);
	*i_d = (char *)malloc(sizeof(char));
	**i_d = '\0';
}

int		main(int argc, char *argv[], char *envp[])
{
	t_main	s;
	t_ok	k;
	char 	**d;
	t_sp	sp;
	pid_t	pid;

	k.ok1 = 1;
	s.paths = NULL;
	s.buff[1] = '\0';
	main_p2(argc, argv, &s.paths, envp);
	while (k.ok1 > 0)
	{
		main_p3(&k, &s.count, &s.i_d);
		while (k.ok2)
		{
			s.count++;
			read(0, s.buff, 1);
			if (*s.buff == '\n')
				k.ok2 = 0;
			else
				s.i_d = ft_realloc(s.i_d, s.buff);
		}
		refresh_path(envp);
		if ((pid =fork()) == 0)
			k.ok1 = (is_special(s.i_d) == 0) ? (compute(s.i_d, s.paths, envp)):
				(ft_implement_functions(s.i_d, &envp));
		else	waitpid(pid, &sp.status, 0);

	}
	return (0);
}
