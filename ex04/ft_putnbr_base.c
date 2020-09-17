/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeshet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:18:50 by mkeshet           #+#    #+#             */
/*   Updated: 2020/09/17 13:03:10 by mkeshet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		strln(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		teststr(char *base)
{
	int i;
	int j;

	if (!base || strln(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i] != base[j] && base[j])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int lng;
	unsigned int unnbr;

	unnbr = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		unnbr = unnbr * (-1);
	}
	lng = strln(base);
	if (teststr(base) && unnbr >= lng)
	{
		ft_putnbr_base(unnbr / lng, base);
		ft_putnbr_base(unnbr % lng, base);
	}
	else
		write(1, &base[unnbr], 1);
}
