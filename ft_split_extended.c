/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_extended.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:05:25 by icheres           #+#    #+#             */
/*   Updated: 2016/01/06 14:24:26 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_split(int *i, int *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = 0;
}

void	st(char **str, char *str_orig, char delim, char ***w)
{
	*str = (char *)malloc(sizeof(char) * (ft_strlen(str_orig) + 1));
	*str = ft_strcpy(*str, str_orig);
	*str = clean(*str, delim);
	*w = (char **)malloc(sizeof(char *) * (ft_words(*str, delim) + 1));
}
