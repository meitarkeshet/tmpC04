/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeshet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:21:34 by mkeshet           #+#    #+#             */
/*   Updated: 2020/09/17 13:07:20 by mkeshet          ###   ########.fr       */
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

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	else
		return (0);
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
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i] != base[j] && base[j])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		if (ft_isspace(base[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}



int		ft_atoi(char *str)
{
	int i;
	int sign;
	int transint;

	i = 0;
	sign = 1;
	transint = 0;
	while (str[i])
	{
		if (!(ft_isspace(str[i]) ||
			str[i] == '+' ||
			str[i] == '-' ||
			(str[i] >= 48 && str[i] <= 57)))
		{
			return (transint * sign);
		}
		if (str[i] == '-')
			sign = sign * (-1);
		if (str[i] >= 48 && str[i] <= 57)
			transint = transint * 10 + str[i] - 48;
		i++;
	}
	return (transint * sign);
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
	if (unnbr >= lng)
	{
		ft_putnbr_base(unnbr / lng, base);
		ft_putnbr_base(unnbr % lng, base);
	}
	else
		write(1, &base[unnbr], 1);
}

 int ft_atoi_base(char *str, char *base)
{
	int nbr;
	
	if (!(ft_atoi(str)))
		return (0);
	else
	{	
		nbr = (ft_atoi(str));
		if (!(teststr(base)))
			return (0);
		else 
		{
		ft_putnbr_base(nbr, base);
			return (1);
		}
	}
}

int		main(void)
{
	char *str = "    200abc 900";
	char *base = "0123456	789abcdef";
	printf("\n%d", ft_atoi_base(str, base));

}




