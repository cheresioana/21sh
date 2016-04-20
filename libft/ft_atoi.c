/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:28:04 by icheres           #+#    #+#             */
/*   Updated: 2016/04/03 14:10:47 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_isspace(int c)
{
	unsigned char ca;

	ca = (unsigned char)c;
	if (ca == '\t' || ca == '\n' || ca == '\v' || ca == '\f'
			|| ca == '\r' || ca == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int nr;
	int neg;

	neg = 1;
	nr = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (str[0] == '-')
		neg = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		nr = nr * 10 + (*str++ - '0');
	nr *= neg;
	return (nr);
}
