/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_ord_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:01:54 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/20 14:20:40 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ls.h"

void				ft_rev_ord_list(t_list *listy)
{
	t_list			*temp;
	char			*tempy;

	temp = listy;
	while (listy->next != NULL)
	{
		if (ft_strcmp(listy->str, listy->next->str) < 0)
		{
			tempy = ft_strdup(listy->next->str);
			listy->next->str = ft_strdup(listy->str);
			listy->str = ft_strdup(tempy);
			listy = temp;
		}
		else
		{
			listy = listy->next;
		}
	}
	listy = temp;

}

void				ft_rev_ord_list_long(t_long *listy)
{

	t_long			*start;
	t_st			tmp;

	start = listy;
	while (listy->next != NULL)
	{
		if (ft_strcmp(listy->seti.d_name, listy->next->seti.d_name) < 0)
		{
			tmp = listy->next->seti;
			listy->next->seti = listy->seti;
			listy->seti = tmp;
			listy = start;
		}
		else
			listy = listy->next;
	}
	listy = start;
}
