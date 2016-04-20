/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:11:20 by icheres           #+#    #+#             */
/*   Updated: 2016/03/23 20:57:30 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		print_env(char **env)
{
	int		index;

	index = 0;
	while (env[index])
	{
		ft_putstr(env[index]);
		write(1, "\n", 1);
		index++;
	}
	return (1);
}

int		return_msj_val(char *str, int val)
{
	ft_putstr(str);
	write(1, "\n", 1);
	return (val);
}

int		r_msj_val(char *msj, char *name, int val)
{
	ft_putstr(msj);
	ft_putstr(name);
	write(1, "\n", 1);
	return (val);
}

void	ft_afis_mat(char **a)
{
	int i;

	i = 0;
	printf("\nafisare mat\n");
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("finis mat\n");
}
