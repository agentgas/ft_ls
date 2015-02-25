/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showhid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:41:48 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 15:46:56 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "./includes/ls.h"

void	ft_hidedot(void)
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
	ft_ord_list(namy);
	ft_print_list(&namy);
}

void	ft_longd(struct dirent *within)
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;

	stat(within->d_name, &stats);
	pwd = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	ft_lnknbr(stats.st_nlink);
	ft_putstr(" ");
	ft_putstr(pwd->pw_name);
	ft_putstr("  ");
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
	ft_affsize(stats.st_size);
	ft_putstr(" ");
	ft_timedis(within);
	ft_putstr("  ");
	ft_putstr(within->d_name);
	ft_putstr("\n");
}

void	ft_timedis(struct dirent *within)
{
	struct stat	stats;
	struct tm	*bttf;

	stat(within->d_name, &stats);
	bttf = gmtime(&(stats.st_mtime));
	ft_choosemonth(bttf->tm_mon);
	ft_putstr(" ");
	ft_putnbr(bttf->tm_mday);
	ft_putstr(" ");
	if (bttf->tm_isdst == 0)
		bttf->tm_hour += 1;
	if (bttf->tm_hour < 10)
		ft_putnbr(0);
	ft_putnbr(bttf->tm_hour);
	ft_putstr(":");
	if (bttf->tm_min < 10)
		ft_putnbr(0);
	ft_putnbr(bttf->tm_min);
}

void	ft_choosemonth(int month)
{
	if (month == 0)
		ft_putstr("Jan");
	if (month == 1)
		ft_putstr("Feb");
	if (month == 2)
		ft_putstr("Mar");
	if (month == 3)
		ft_putstr("Apr");
	if (month == 4)
		ft_putstr("May");
	if (month == 5)
		ft_putstr("Jun");
	if (month == 6)
		ft_putstr("Jul");
	if (month == 7)
		ft_putstr("Aug");
	if (month == 8)
		ft_putstr("Sep");
	if (month == 9)
		ft_putstr("Oct");
	if (month == 10)
		ft_putstr("Nov");
	if (month == 11)
		ft_putstr("Dec");
}

void	ft_affsize(int size)
{
	if (size > 9 && size <= 99)
		ft_putstr("   ");
	else if (size > 99 && size <= 999)
		ft_putstr("  ");
	else if (size > 999 && size <= 9999)
		ft_putstr(" ");
	else if (size < 10)
		ft_putstr("    ");
	ft_putnbr(size);
	ft_putstr(" ");
}
