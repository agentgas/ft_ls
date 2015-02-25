/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:02:59 by glovichi          #+#    #+#             */
/*   Updated: 2015/02/03 14:00:03 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/ls.h"

static char	*ft_putstrin_sign(int sizebuff, int n)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(sizeof(sizebuff + 1));
	str[0] = '-';
	if (n > 9)
	{
		while (sizebuff > 0)
		{
			str[sizebuff] = ('0' + (n % 10));
			n /= 10;
			sizebuff -= 1;
			i += 1;
		}
		str[i] = '\0';
		return (str);
	}
	else
		str[sizebuff] = ('0' + (n % 10));
	str[i + 1] = '\0';
	return (str);
}

static char	*ft_invers(char *str)
{
	int		i;
	int		y;
	char	*ret;

	i = 0;
	y = ft_strlen(str) - 1;
	ret = (char *)malloc(sizeof(str) + 1);
	while (str[i] != '\0')
	{
		ret[y] = str[i];
		i += 1;
		y -= 1;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_putstrin(int sizebuff, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(sizebuff + 1));
	if (n > 9)
	{
		while (n > 9)
		{
			str[i] = ('0' + (n % 10));
			n /= 10;
			sizebuff -= 1;
			i += 1;
		}
	}
	str[i] = ('0' + (n % 10));
	str[i + 1] = '\0';
	str = ft_invers(str);
	return (str);
}

char		*ft_itoa(int n)
{
	int		sizebuff;
	int		tmp;
	int		sign;
	char	*ret;

	sizebuff = 1;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
		sizebuff += 1;
	}
	if ((tmp = n) > 9)
	{
		while (tmp > 9)
		{
			tmp /= 10;
			sizebuff += 1;
		}
	}
	return ((sign == 1) ? (ret = ft_putstrin_sign(sizebuff - 1, n))
	: (ret = ft_putstrin(sizebuff, n)));
}
