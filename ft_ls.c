/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 09:17:59 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/15 17:20:51 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ls.h"

void	ft_rights()
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		stats;

	arep = opendir(".");
	if (arep == NULL)
		ft_putstr("Nein: open failed like a boss");
	ft_showblock();
	while ((within = readdir(arep)) != NULL)
		if ((within->d_name)[0] != '.')
		{
			stat(within->d_name, &stats);
			ft_putstr(((S_ISDIR(stats.st_mode)) ? "d" : "-"));
			ft_putstr(((stats.st_mode & S_IRUSR) == S_IRUSR) ? "r" : "-");
			ft_putstr(((stats.st_mode & S_IWUSR) == S_IWUSR) ? "w" : "-");
			ft_putstr(((stats.st_mode & S_IXUSR) == S_IXUSR) ? "x" : "-");
			ft_putstr(((stats.st_mode & S_IRGRP) == S_IRGRP) ? "r" : "-");
			ft_putstr(((stats.st_mode & S_IWGRP) == S_IWGRP) ? "w" : "-");
			ft_putstr(((stats.st_mode & S_IXGRP) == S_IXGRP) ? "x" : "-");
			ft_putstr(((stats.st_mode & S_IROTH) == S_IROTH) ? "r" : "-");
			ft_putstr(((stats.st_mode & S_IWOTH) == S_IWOTH) ? "w" : "-");
			ft_putstr(((stats.st_mode & S_IXOTH) == S_IXOTH) ? "x  " : "-  ");
			ft_longd(within);
		}
}

void	ft_calldisplay(int x)
{
	if (x == 1)
		ft_rights();
	else if (x == 2)
	{
		ft_subside();
		ft_putstr("\n");
	}
	else if (x == 3)
		ft_showhide();
	else
		ft_hidedot();
}

void	ft_wichopt(char *opt)
{
	int 	k;
	char	*l;
	char	*a;
	char	*RR;

	k = 0;
	l = "-l";
	a = "-a";
	RR = "-R";
	if (ft_cmpstr(l, opt) == 0)
		ft_calldisplay(1);
	else if (ft_cmpstr(a, opt) == 0)
		ft_calldisplay(3);
	else if (ft_cmpstr(RR, opt) == 0)
		ft_calldisplay(2);
	else
		ft_putstr("No valid Argument\n");
}

int		main(int ac, char **av)
{
	int		i;

	i = ac - 1;
	if (ac == 1)
		ft_calldisplay(0);
	else
		while (i > 0)
		{
			ft_wichopt(av[i]);
			i -= 1;
		}
	return (0);
}
