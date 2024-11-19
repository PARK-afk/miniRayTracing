/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:20:40 by junsepar          #+#    #+#             */
/*   Updated: 2022/12/01 17:14:10 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	ch;

	d = (unsigned char *) b;
	ch = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		d[i] = ch;
		i++;
	}
	return (b);
}
