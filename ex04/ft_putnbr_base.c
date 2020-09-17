/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeshet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:18:50 by mkeshet           #+#    #+#             */
/*   Updated: 2020/09/16 22:12:29 by mkeshet          ###   ########.fr       */
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

//	printf("%d", strln(base));
	if (!base || strln(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == 'i')
			return (0);
		while (base[i] != base[j + 1] && base[j])
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
	int lng;
	lng = strln(base);

		if (nbr >= 0 && nbr < lng)
		{
			write(1, &nbr, 1);
		}

	if (teststr(base) && nbr >= lng)
	{
	ft_putnbr_base(nbr / lng, base);
	ft_putnbr_base(nbr % lng, base);
	}
	else
		write(1, &base[nbr], 1);
}

int		main(void)
{
	int nbr = 12525;

	char base[] = "0123456789";

	ft_putnbr_base(nbr, base);

	return (0);
}
