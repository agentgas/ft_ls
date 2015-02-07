/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subside.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:01:58 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/15 17:28:49 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "ls.h"

void	ft_subside()
{
	DIR				*arep;
	struct dirent	*within;

	arep = opendir(".");
	if (arep == NULL)
		ft_putstr("Nein: open failed like a boss");
	while ((within = readdir(arep)) != NULL)
	{
		if (within->d_type == DT_DIR && (within->d_name)[0] != '.')
		{
			ft_putstr("./");
/*			ft_putstr(within->d_name);*/
			ft_putstr(":\n");
			arep = opendir(within->d_name);
			while ((within = readdir(arep)) != NULL)
			{
				ft_hidedot(within->d_name, within);
			}
		}
	}
}
