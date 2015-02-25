/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:57:02 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/19 11:29:07 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*strike;

	i = 0;
	y = 0;
	strike = (char *)(malloc(sizeof(*s1 + *s2)));
	while (s1[i] != '\0')
	{
		strike[i] = s1[i];
		i += 1;
	}
	while (s2[y] != '\0')
	{
		strike[i] = s2[y];
		i += 1;
		y += 1;
	}
	strike[i] = '\0';
	return (strike);
}
