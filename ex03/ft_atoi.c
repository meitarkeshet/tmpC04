/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeshet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:23:53 by mkeshet           #+#    #+#             */
/*   Updated: 2020/09/16 16:57:21 by mkeshet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
