/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:02:26 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 16:25:30 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>

#include <stdio.h>

#include "./includes/ls.h"

void				ft_sort_it(t_list *timy)
{
	t_list			*newl;
	unsigned int	tmp;
	char			*tempy;

	newl = timy->next;
	while (newl)
	{
		if (newl->str == NULL)
			break ;
		if (newl->prev->str != NULL)
		{
			if (newl->date > newl->prev->date)
			{
				tmp = newl->prev->date;
				tempy = newl->prev->str;
				newl->prev->date = newl->date;
				newl->prev->str = newl->str;
				newl->date = tmp;
				newl->str = tempy;
				newl = timy->next;
			}
		}
		newl = newl->next;
	}
	ft_print_list(&timy);
}

void				ft_time_sort(void)
{
	DIR				*arep;
	struct dirent	*within;
	struct stat		st;
	t_list			*timy;

	arep = opendir(".");
	while ((within = readdir(arep)) != NULL)
	{
		if ((within->d_name)[0] != '.')
		{
			stat(within->d_name, &st);
			ft_add_lnk(ft_nl(within->d_name, st.st_mtime), &timy);
		}
	}
	closedir(arep);
	ft_sort_it(timy);
}
