/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 12:40:53 by icheres           #+#    #+#             */
/*   Updated: 2016/03/23 20:56:51 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(char *data, char *buff)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(data) + 2));
	i = 0;
	while (data[i])
	{
		dest[i] = data[i];
		i++;
	}
	dest[i] = buff[0];
	dest[i + 1] = '\0';
	free(data);
	return (dest);
}

char	*comp(char *s1, char *s2)
{
	char	*rez;
	t_sp	sp;

	sp.i = 0;
	sp.j = 0;
	rez = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s2) + 1));
	while (s1[sp.i])
	{
		rez[sp.i] = s1[sp.i];
		sp.i++;
	}
	rez[sp.i] = '/';
	sp.i++;
	while (s2[sp.j])
	{
		rez[sp.i] = s2[sp.j];
		sp.i++;
		sp.j++;
	}
	rez[sp.i] = '\0';
	return (rez);
}

void	concat_with_ext(t_sp *s, char **result, char **array)
{
	s->i = 1;
	s->size = 0;
	s->j = 1;
	while (array[s->i])
	{
		s->size += ft_strlen(array[s->i]);
		s->i++;
	}
	*result = (char *)malloc(sizeof(char) * (s->size + 1));
	s->size = 0;
}

char	*concat_with(char **array, char delim)
{
	char	*result;
	t_sp	s;

	concat_with_ext(&s, &result, array);
	while (array[s.j])
	{
		s.i = 0;
		while (array[s.j][s.i])
		{
			result[s.size] = array[s.j][s.i];
			s.i++;
			s.size++;
		}
		if (array[s.j + 1])
		{
			result[s.size] = delim;
			s.size++;
		}
		s.j++;
	}
	result[s.size] = '\0';
	return (result);
}

char	**del_from_matrix(char **m, int index)
{
	while (m[index + 1])
	{
		m[index] = m[index + 1];
		index++;
	}
	m[index] = NULL;
	return (m);
}
