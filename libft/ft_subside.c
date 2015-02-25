/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subside.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:01:58 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/24 09:33:17 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "./includes/ls.h"

#include <stdio.h>

char				*ft_make_rep_name(char *d_name)
{
	char			*ret;

	ret = ft_strdup("\n");
	/*ret = ft_strjoin(ret, "./");*/
	ret = ft_strjoin(ret, d_name);
	ret = ft_strjoin(ret, ":");
	return (ret);
}

int					ft_isthere_dir(char *diry)
{
	DIR				*arep;
	struct dirent	*within;
	int				i;

	i = 0;
	arep = opendir(diry);
	while ((within = readdir(arep)) != NULL)
	{
		if (within->d_type == DT_DIR && (within->d_name)[0] != '.')
		{
			i += 1;
		}
	}
	closedir(arep);
	return (i);
}

t_list				*ft_get_dir_list(char *diry)
{
	DIR				*arep;
	struct dirent	*within;
	int				x;
	t_list			*d_list;

	/*d_list = (t_list *)malloc(sizeof(t_list));*/
	x = 0;
	ft_putendl("ft_make_dir_list");
	arep = opendir(diry);
	if (arep == NULL)
	{
		ft_putendl("So Sorry Sir: opendir has just failed like a boss.");
	}
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_type == DT_DIR) && (within->d_name)[0] != '.')
		{
			ft_putstr("DIR: ");
			ft_putendl(within->d_name);
			ft_add_lnk(ft_nl(within->d_name, 0), &d_list);
			x += 1;
		}
	}
	closedir(arep);
	ft_putendl("ft_make_dir_list_ed");
	return (d_list);
}

t_list				*ft_make_list(char *where)
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		st;
	t_list			*files;

	arep = opendir(where);
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] != '.')
		{
			stat(within->d_name, &st);
			ft_add_lnk(ft_nl(within->d_name, 0), &files);
		}
	}
	closedir(arep);
	ft_putendl("ft_make_list_ed");
	return (files);
}

void				ft_subside(char *where)
{
	t_list			*files;
	t_list			*john;
	char			*path;
	int				i;

	/*files = (t_list *)malloc(sizeof(t_list));*/
	john = (t_list *)malloc(sizeof(t_list));
	path = ft_strdup(where);
	printf("Start:\nfily directory path: [%s]\n", path);
	files = ft_make_list(path);
	ft_get_dir_list(where);
	i = ft_isthere_dir(where);
	ft_putendl("debug1");
	ft_putstr("john->str: ");
	if (john->str != NULL)
		ft_putendl(john->str);
	if (i != 0)
	{
		while (john)
		{
			if (john->str != NULL)
			{
				path = ft_strdup(where);
				path = ft_strjoin(path, "/");
				path = ft_strjoin(path, john->str);
				ft_putendl("");
				ft_putstr(path);
				ft_putendl(":");
				ft_subside(path);
			}
			if (john->next != NULL)
				john = john->next;
		}
	}
	else if (files)
		ft_print_list(&files);
}
