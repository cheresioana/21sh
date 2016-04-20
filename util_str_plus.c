/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:07:39 by icheres           #+#    #+#             */
/*   Updated: 2016/04/10 17:09:54 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*minus(char *d, char *s)
{
	int		ok;
	int		i;

	ok = 1;
	i = 0;
	s += 1;
	d += 1;
	while (d[i] == s[i] || ok)
	{
		if (d[i] == s[i])
			ok = 0;
		i++;
	}
	return (d + i);
}

void	ft_putstr_s(char *s1, char *s2)
{
	ft_putstr(s1);
	write(1, " ", 1);
	ft_putstr(s2);
	write(1, "\n", 1);
}

char	*clean_spaces(char *s)
{
	int		i;
	int		j;

	while (*s == ' ' && *s != '\0')
		s++;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && (s[i + 1] == '\0' || s[i + 1] == ' '))
		{
			j = i;
			do
			{	
				j++;
				s[j - 1] = s[j];
			}while (s[j] != '\0');
		}
		i++;
	}
	return (s);
}
