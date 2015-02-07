/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 09:59:00 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/15 17:44:52 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>

void	ft_putstr(char const *s);
void	ft_putnbr(int n);
void	ft_rights();
void	ft_calldisplay(int x);
void	ft_wichopt(char *opt);
int		ft_cmpstr(char *str, char *str2);
int		ft_strlen(const char *str);
void	ft_hidedot();
void	ft_longd(struct dirent *within);
void	ft_timedis(struct dirent *within);
void	ft_showhide();
void	ft_subside();
void	ft_choosemonth(int month);
void	ft_affsize(int size);
void	ft_lnknbr(int link);
void	ft_showblock();

#endif /* !LS_H */
