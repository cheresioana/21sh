/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:10:03 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 20:10:06 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	*ft_poz(char const *s, char c)
{
	int		*tablo;
	char	*aux;
	size_t	vars[3];

	vars[0] = ft_strlen(s);
	tablo = (int *)malloc(sizeof(int) * (vars[0] * 2));
	while (vars[0]--)
		*tablo++ = -1;
	aux = (char *)s;
	vars[1] = 1;
	while (*aux)
	{
		while (*aux && *aux == c)
			aux++;
		if (*aux == 0)
			continue;
		vars[2] = 0;
		tablo[vars[1]++] = (s - aux) * (-1);
		while (*aux && *aux != '*')
			aux++, vars[2]++;
		tablo[vars[1]++] = vars[2];
		if (*aux || *(aux - 1) != '*')
			tablo[0]++, aux++;
	}
	return (tablo);
}

char		**ft_strsplit(char const *s, char c)
{
	int		*tablo;
	int		i;
	char	**matrix;
	char	*aux;
	int		vars[2];

	tablo = ft_poz(s, c);
	if (tablo[0] == -1)
		return (0);
	matrix = (char **)malloc(sizeof(char *) * (tablo[0] + 1));
	vars[0] = 0;
	i = 1;
	while (vars[0] < tablo[0])
	{
		i++;
		matrix[vars[0]] = (char *)malloc(sizeof(char) * (tablo[i] + 1));
		aux = (char *)s + tablo[i - 1];
		vars[1] = 0;
		while (*aux && vars[1] < tablo[i])
			matrix[vars[0]][vars[1]++] = *aux++;
		matrix[vars[0]][vars[1]] = 0;
		i++;
		vars[0]++;
	}
	return (matrix);
}
