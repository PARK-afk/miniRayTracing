/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:41:14 by junsepar          #+#    #+#             */
/*   Updated: 2022/11/29 20:13:39 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int		nl;
	long	nbr;

	nbr = (long) n;
	nl = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr *= -1;
		nl++;
	}
	while (nbr)
	{
		nbr /= 10;
		nl++;
	}
	return (nl);
}

char	*ft_itoa(int n)
{
	int			nl;
	char		*str;
	long int	nbr;

	nbr = (long int) n;
	nl = nbr_len(n);
	str = (char *)malloc(sizeof(char) * nl + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[nl] = '\0';
	while (nbr)
	{
		nl--;
		str[nl] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
