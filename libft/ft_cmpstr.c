/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:12:29 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/14 10:45:36 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*int	ft_chooseoption(char *str)
{
	char *option[3][4];
}
*/
int	ft_cmpstr(char *str, char *str2)
{
	int		i;
	int		ok;
	int		lenstr;

	i = 0;
	ok = 0;
	lenstr = ft_strlen(str);
	while (i != lenstr)
	{
		if (str[i] == str2[i])
			ok += 1;
		else
			break;
		i += 1;
	}
	if (ok == lenstr)
		return (0);
	else
		return (1);
}
