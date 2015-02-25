
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "./includes/ls.h"
#include <stdio.h>

char	*ft_month2(int month)
{
	char *monthstr;

	if (month == 5)
		monthstr = ft_strdup("Jun");
	if (month == 6)
		monthstr = ft_strdup("Jul");
	if (month == 7)
		monthstr = ft_strdup("Aug");
	if (month == 8)
		monthstr = ft_strdup("Sep");
	if (month == 9)
		monthstr = ft_strdup("Oct");
	if (month == 10)
		monthstr = ft_strdup("Nov");
	if (month == 11)
		monthstr = ft_strdup("Dec");
	return (monthstr);
}

char	*ft_month(int month)
{
	char	*monthstr;

	if (month == 0)
		monthstr = ft_strdup("Jan");
	if (month == 1)
		monthstr = ft_strdup("Feb");
	if (month == 2)
		monthstr = ft_strdup("Mar");
	if (month == 3)
		monthstr = ft_strdup("Apr");
	if (month == 4)
		monthstr = ft_strdup("May");
	else
		monthstr = ft_month2(month);
	return (monthstr);
}

char		*ft_timestr2(struct dirent *within, char *timestr)
{
	struct stat	stats;
	struct tm	*bttf;

	stat(within->d_name, &stats);
	bttf = gmtime(&(stats.st_mtime));
	if (bttf->tm_isdst == 0)
		bttf->tm_hour += 1;
	if (bttf->tm_hour < 10)
	{
		timestr = ft_strjoin(ft_strdup(ft_itoa(bttf->tm_hour)), timestr);
		timestr = ft_strjoin("0", timestr);
	}
	else
		timestr = ft_strjoin(ft_strdup(ft_itoa(bttf->tm_hour)), timestr);
	timestr = ft_strjoin(" ", timestr);
	timestr = ft_strjoin(ft_strdup(ft_month(bttf->tm_mon)), timestr);
	timestr = ft_strjoin(" ", timestr);

	timestr = ft_strjoin(ft_strdup(ft_itoa(bttf->tm_mday)), timestr);
	timestr = ft_strjoin(" ", timestr);
	return (timestr);
}

char	*ft_timestr(struct dirent *within)
{
	struct stat	stats;
	struct tm	*bttf;
	char		*timestr;

	timestr = ft_strdup("");
	stat(within->d_name, &stats);
	bttf = gmtime(&(stats.st_mtime));

	if (bttf->tm_min < 10)
	{
		timestr = ft_strjoin(ft_strdup(ft_itoa(bttf->tm_min)), timestr);
		timestr = ft_strjoin("0", timestr);
	}
	else
		timestr = ft_strjoin(ft_strdup(ft_itoa(bttf->tm_min)), timestr);
	timestr = ft_strjoin(":", timestr);
	timestr = ft_timestr2(within, timestr);
	return (timestr);
}

t_st				ft_add_to_struc(t_st x, struct dirent *within)
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;
	
	stat(within->d_name, &stats);
	pwd = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	x.ISDIR = ((S_ISDIR(stats.st_mode)) ? 'd' : '-');
	x.IRUSR = (((stats.st_mode & S_IRUSR) == S_IRUSR) ? 'r' : '-');
	x.IWUSR = (((stats.st_mode & S_IWUSR) == S_IWUSR) ? 'w' : '-');
	x.IXUSR = (((stats.st_mode & S_IXUSR) == S_IXUSR) ? 'x' : '-');
	x.IRGRP = (((stats.st_mode & S_IRGRP) == S_IRGRP) ? 'r' : '-');
	x.IWGRP = (((stats.st_mode & S_IWGRP) == S_IWGRP) ? 'w' : '-');
	x.IXGRP = (((stats.st_mode & S_IXGRP) == S_IXGRP) ? 'x' : '-');
	x.IROTH = (((stats.st_mode & S_IROTH) == S_IROTH) ? 'r' : '-');
	x.IWOTH = (((stats.st_mode & S_IWOTH) == S_IWOTH) ? 'w' : '-');
	x.IXOTH = (((stats.st_mode & S_IXOTH) == S_IXOTH) ? 'x' : '-');
	x.nlink = stats.st_nlink;
	x.pw_name = pwd->pw_name;
	x.gr_name = grp->gr_name;
	x.size = stats.st_size;
	x.date = ft_timestr(within);
	x.d_name = within->d_name;
	return (x);
}

void				ft_longlong(int x)
{
	DIR				*arep;
	struct dirent	*within;
	t_st			ll;
	t_long			*long_list;


	arep = opendir(".");
	if (arep == NULL)
		ft_putstr("Nein: open failed like a boss");
	ft_showblock();
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] != '.')
		{
			ll = ft_add_to_struc(ll, within);
			ft_add_lnk_long(ft_nl_long(ll), &long_list);
		}
	}
	closedir(arep);
	ft_ord_list_long(long_list);
	if (x == 2)
		ft_rev_ord_list_long(long_list);
	ft_print_list_long(&long_list);
}

void				ft_longlongall(int x)
{
	DIR				*arep;
	struct dirent	*within;
	t_st			ll;
	t_long			*long_list;

	arep = opendir(".");
	if (arep == NULL)
		ft_putstr("Nein: open failed like a boss");
	ft_showblock();
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] != '.' || (within->d_name)[0] == '.')
		{
			ll = ft_add_to_struc(ll, within);
			ft_add_lnk_long(ft_nl_long(ll), &long_list);
		}
	}
	closedir(arep);
	ft_ord_list_long(long_list);
	if (x == 2)
		ft_rev_ord_list_long(long_list);
	ft_print_list_long(&long_list);
}
