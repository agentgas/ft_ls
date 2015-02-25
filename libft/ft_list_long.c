/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:03:53 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 15:44:43 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ls.h"

#include <stdio.h>

t_long				*ft_nl_long(t_st ll)
{
	t_long	*newl;

	if ((newl = (t_long *)malloc(sizeof(t_long))) == NULL)
		return (NULL);
	newl->ISDIR = ll.ISDIR;
	newl->IRUSR = ll.IRUSR;
	newl->IWUSR = ll.IWUSR;
	newl->IXUSR = ll.IXUSR;
	newl->IRGRP = ll.IRGRP;
	newl->IWGRP = ll.IWGRP;
	newl->IXGRP = ll.IXGRP;
	newl->IROTH = ll.IROTH;
	newl->IWOTH = ll.IWOTH;
	newl->IXOTH = ll.IXOTH;
	newl->nlink = ll.nlink;
	newl->pw_name = ll.pw_name;
	newl->gr_name = ll.gr_name;
	newl->size = ll.size;
	newl->date = ll.date;
	newl->d_name = ll.d_name;
	newl->seti = ll;
	newl->next = NULL;
	newl->prev = NULL;
	return (newl);
}

void		ft_add_link_start_long(t_long *newl, t_long **list)
{
	newl->next = *list;
	*list = newl;
}

void		ft_add_lnk_long(t_long *newl, t_long **list)
{
	t_long	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newl;
		newl->prev = tmp;
	}
	else
		*list = newl;
}

int						ft_longest_size(t_long *list)
{
	t_long				*tmp;
	unsigned int		longest;
	int		ret;

	tmp = list;
	longest = 0;
	ret = 0;
	if (tmp)
	{
		while(tmp->next != NULL)
		{
			if (tmp->seti.size > longest)
				longest = tmp->seti.size;
			tmp = tmp->next;
		}
	}
	if (tmp->seti.size > longest)
	longest = tmp->seti.size;

	ret = ft_strlen(ft_itoa(longest));
	return (ret);
}

void		ft_print_more(t_long *list)
{
	write(1, &list->seti.ISDIR, 1);
	write(1, &list->seti.IRUSR, 1);
	write(1, &list->seti.IWUSR, 1);
	write(1, &list->seti.IXUSR, 1);
	write(1, &list->seti.IRGRP, 1);
	write(1, &list->seti.IWGRP, 1);
	write(1, &list->seti.IXGRP, 1);
	write(1, &list->seti.IROTH, 1);
	write(1, &list->seti.IWOTH, 1);
	write(1, &list->seti.IXOTH, 1);
	if (list->seti.nlink > 10)
		ft_putstr("  ");
	else
		ft_putstr("   ");
	ft_putnbr(list->seti.nlink);
	ft_putstr(" ");
	ft_putstr(list->seti.pw_name);
	ft_putstr("  ");
	ft_putstr(list->seti.gr_name);
}

void		ft_print_even_more(t_long *list, int longest)
{
	int		tempint;

	tempint = ft_strlen(ft_itoa(list->seti.size));
	if (tempint < longest)
	{
		while (tempint < longest)
		{
			ft_putstr(" ");
			tempint += 1;
		}
	}
	ft_putstr("  ");
	ft_putnbr(list->seti.size);
	ft_putstr(list->seti.date);
	ft_putstr(" ");
	ft_putendl(list->seti.d_name);
}

void		ft_print_list_long(t_long **list)
{
	t_long	*tmp;
	t_long	*sizelist;
	int		longest;

	sizelist = *list;
	longest = ft_longest_size(sizelist);
	tmp = *list;
	if (tmp)
	{
		while (tmp->d_name != NULL)
		{
			if (tmp->ISDIR)
			{
				ft_print_more(tmp);
				ft_print_even_more(tmp, longest);

			}
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
		}
	}
}

void		ft_del_link_long(int posy, t_long *list)
{
	while (posy > 0)
	{
		list = list->next;
		posy -= 1;
	}
	if (list->next != NULL)
	{
		list->next = list->next->next;
		free(list->next);
	}
}
