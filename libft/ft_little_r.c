/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:04:39 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 15:50:15 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "./includes/ls.h"

void		ft_little_ra(void)
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		st;
	t_list			*namy;

	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		stat(within->d_name, &st);
		ft_add_lnk(ft_nl(within->d_name, st.st_mtime), &namy);
	}
	closedir(arep);
	ft_rev_ord_list(namy);
	ft_print_list(&namy);
}

void		ft_little_r(void)
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		st;
	t_list			*namy;

	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] != '.')
		{
			stat(within->d_name, &st);
			ft_add_lnk(ft_nl(within->d_name, st.st_mtime), &namy);
		}
	}
	closedir(arep);
	ft_rev_ord_list(namy);
	ft_print_list(&namy);
}
