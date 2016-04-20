/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 12:52:08 by icheres           #+#    #+#             */
/*   Updated: 2016/01/06 14:24:39 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_special_chars(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n')
			aux[i] = ' ';
		else
			aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*clean(char *str, char del)
{
	t_sp	s;
	char	*aux;

	s.i = 0;
	s.j = 0;
	if (del == ' ')
		str = clean_special_chars(str);
	while (str[s.i] == del)
		s.i++;
	str += s.i;
	s.i = 0;
	aux = (char	*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[s.i])
	{
		if (str[s.i] == del && (str[s.i + 1] == '\0' || str[s.i + 1] == del))
			s.i++;
		else
		{
			aux[s.j] = str[s.i];
			s.j++;
			s.i++;
		}
	}
	aux[s.j] = '\0';
	return (aux);
}

int		ft_words(char *s, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == delim)
			count++;
		i++;
	}
	return (count + 1);
}

char	**ft_split_whitespaces(char *str_orig, char delim)
{
	char	**w;
	t_sp	s;
	char	*str;

	if (str_orig == NULL)
		return (NULL);
	init_split(&s.i, &s.j, &s.index);
	st(&str, str_orig, delim, &w);
	while (str[s.i])
	{
		s.j = 0;
		w[s.index] = (char *)malloc(sizeof(char) * (ft_strlen(str + s.i) + 1));
		while (str[s.i] != '\0' && str[s.i] != delim)
		{
			w[s.index][s.j] = str[s.i];
			s.i++;
			s.j++;
		}
		if (str[s.i])
			s.i++;
		w[s.index][s.j] = '\0';
		s.index++;
	}
	w[s.index] = NULL;
	return (w);
}
