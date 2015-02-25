/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_train.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:03:53 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 15:44:43 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ls.h"

t_list		*ft_nl(char *str, unsigned int modate)
{
	t_list	*newl;

	if ((newl = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((newl->str = (char *)(malloc(sizeof(ft_strlen(str))))) == NULL)
		return (NULL);
	newl->str = str;
	newl->date = modate;
	newl->next = NULL;
	newl->prev = NULL;
	return (newl);
}

void		ft_add_link_start(t_list *newl, t_list **list)
{
	newl->next = *list;
	*list = newl;
}

void		ft_add_lnk(t_list *newl, t_list **list)
{
	t_list	*tmp;

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

void		ft_print_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			if (tmp->str)
				ft_putendl(tmp->str);
			tmp = tmp->next;
		}
		ft_putendl(tmp->str);
	}
}

void		ft_del_link(int posy, t_list *list)
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
