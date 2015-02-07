/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backwrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 11:15:14 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/15 17:18:58 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ls.h"

void	ft_showhide()
{
	DIR				*arep;
	struct dirent	*within;

	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		ft_putstr(within->d_name);
		ft_putstr("\n");
	}
	closedir(arep);
}

void	ft_showblock()
{
	size_t			allblocks;
	DIR				*arep;
	struct stat		statb;
	struct dirent	*within;

	allblocks = 0;
	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		stat(within->d_name, &statb);
		allblocks = allblocks + (statb.st_blocks);
	}
	closedir(arep);
	ft_putstr("total ");
	ft_putnbr(allblocks);
	ft_putstr("\n");
}
