/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:41:00 by glovichi          #+#    #+#             */
/*   Updated: 2013/12/13 16:54:51 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_putnbr(int n)
{
	int i;
	int tmp;

	i = 0;
	tmp = n;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		i += 1;
	}
	write(1, &n, i + 1);
	}*/

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int             ft_putnbr(int nb)
{
	ft_putchar(nb < 0 && (nb *= -1) ? '-' : '\0');
	ft_putchar(nb - (nb >= 10 ? ft_putnbr(nb / 10) : 0) + 48);
	return (nb * 10);
}
