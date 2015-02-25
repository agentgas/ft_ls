/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 09:59:00 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/21 11:48:11 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			*str;
	int				size;
	unsigned int	date;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

typedef struct		s_st
{
	char			ISDIR;
	char			IRUSR;
	char			IWUSR;
	char			IXUSR;
	char			IRGRP;
	char			IWGRP;
	char			IXGRP;
	char			IROTH;
	char			IWOTH;
	char			IXOTH;
	int				nlink;
	char			*pw_name;
	char			*gr_name;
	unsigned int	size;
	char			*date;
	char			*d_name;
}					t_st;

typedef struct		s_long
{
	char			ISDIR;
	char			IRUSR;
	char			IWUSR;
	char			IXUSR;
	char			IRGRP;
	char			IWGRP;
	char			IXGRP;
	char			IROTH;
	char			IWOTH;
	char			IXOTH;
	int				nlink;
	char			*pw_name;
	char			*gr_name;
	unsigned int	size;
	char			*date;
	char			*d_name;
	t_st			seti;
	struct s_long	*next;
	struct s_long	*prev;
}					t_long;

t_list				*ft_fily(char *diry);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_rights();
void				ft_calldisplay(int x);
void				ft_wichopt(char *opt);
int					ft_cmpstr(char *str, char *str2);
int					ft_strlen(const char *str);

void				ft_hidedot();
void				ft_longd(struct dirent *within);
void				ft_timedis(struct dirent *within);
void				ft_showhide();
void				ft_subside(char *where);
void				ft_choosemonth(int month);
void				ft_affsize(int size);
void				ft_lnknbr(int link);
void				ft_showblock();
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl(char const *s);
char				*ft_strdup(const char *s1);
void				ft_little_r(void);
void				ft_little_ra(void);
void				ft_time_sort(void);
void				ft_longlong(int x);
void				ft_longlongall(int x);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);
t_list				*ft_nl(char *str, unsigned int modate);
void				ft_add_link_start(t_list *newl, t_list **list);
void				ft_add_lnk(t_list *newl, t_list **list);
void				ft_print_list(t_list **list);
void				ft_del_link(int posy, t_list *list);

t_long				*ft_nl_long(t_st ll);
void				ft_add_link_start_long(t_long *newl, t_long **list);
void				ft_add_lnk_long(t_long *newl, t_long **list);
void				ft_print_list_long(t_long **list);
void				ft_del_link_long(int posy, t_long *list);

void				ft_ord_list(t_list *listy);
void				ft_rev_ord_list(t_list *listy);
void				ft_ord_list_long(t_long *listy);
void				ft_rev_ord_list_long(t_long *listy);

#endif
