/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:08:16 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/19 12:45:14 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./includes/ls.h"

char *ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	cp = ((char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1));
	if (!cp)
		return (NULL);
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i += 1;
	}
	cp[i] = '\0';
	return (cp);
}
