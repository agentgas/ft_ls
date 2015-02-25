/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backwrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 11:15:14 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/21 09:00:01 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "./includes/ls.h"

void	ft_showhide(void)
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		st;
	t_list			*namy;

	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] == '.')
		{
			stat(within->d_name, &st);
			ft_add_lnk(ft_nl(within->d_name, 0), &namy);
		}
		if ((within->d_name)[0] != '.')
		{
			stat(within->d_name, &st);
			ft_add_lnk(ft_nl(within->d_name, 0), &namy);
		}
	}
	closedir(arep);
	ft_ord_list(namy);
	ft_print_list(&namy);
}

void	ft_showblock(void)
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
