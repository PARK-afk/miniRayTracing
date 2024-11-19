/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:59:32 by junsepar          #+#    #+#             */
/*   Updated: 2022/12/01 17:01:47 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!len)
		return (0);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j] && i < len)
		{
			while (haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
				if (i + j >= len)
					return (NULL);
			}
		}
		i++;
	}
	return (0);
}
