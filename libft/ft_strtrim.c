/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:54:44 by junsepar          #+#    #+#             */
/*   Updated: 2022/12/14 15:14:19 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sta;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != NULL && set != NULL)
	{
		sta = 0;
		end = ft_strlen((char *)s1);
		while (sta < end && ft_strchr(set, s1[sta]))
			sta++;
		while (end > 0 && ft_strchr(set, s1[end - 1]) && sta < end)
			end--;
		str = (char *)malloc(sizeof(char) * (end - sta + 1));
		if (str == NULL)
			return (0);
		ft_strlcpy(str, &s1[sta], end - sta + 1);
	}
	return (str);
}
