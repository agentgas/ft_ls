/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:12:29 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/18 16:45:14 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ls.h"

int		ft_cmpstr(char *str, char *str2)
{
	int		i;
	int		ok;
	int		lenstr;
	int		lenstr2;

	i = 0;
	ok = 0;
	lenstr = ft_strlen(str);
	lenstr2 = ft_strlen(str2);
	if (lenstr == lenstr2)
	{
		while (i != lenstr)
		{
			if (str[i] == str2[i])
				ok += 1;
			else
				break ;
			i += 1;
		}
	}
	if (ok == lenstr)
		return (0);
	else
		return (1);
}
