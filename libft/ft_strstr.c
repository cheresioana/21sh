/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:24:25 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 21:02:39 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			k = i;
			j = 0;
			while (s1[k] == s2[j] && s2[j] != '\0')
				j++, k++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return ("\0");
}
