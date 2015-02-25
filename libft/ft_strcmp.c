/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:27:31 by glovichi          #+#    #+#             */
/*   Updated: 2015/01/31 13:11:16 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] == s1[i])
		i += 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
