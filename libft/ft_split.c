/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:54:15 by junsepar          #+#    #+#             */
/*   Updated: 2023/12/30 21:19:26 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_word_count(char *s, char *sep)
{
	int	i;
	int	count;
	int	is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i])
	{
		if (!is_separator(s[i], sep) && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (is_separator(s[i], sep))
		{
			is_word = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_sp(char const *s, char *str, size_t i, size_t j)
{
	size_t	idx;

	idx = 0;
	while (j < i + 1)
	{
		str[idx] = s[j];
		j++;
		idx++;
	}
	str[idx] = '\0';
}

static void	ft_ss(char const *s, char *sep, char **str)
{
	size_t	i;
	size_t	stri;
	size_t	j;

	i = 0;
	stri = 0;
	j = 0;
	while (s[i])
	{
		if (!is_separator(s[i], sep) && \
				(is_separator(s[i + 1], sep) || s[i + 1] == '\0'))
		{
			str[stri] = (char *)malloc(sizeof(char) * (i - j + 2));
			if (str[stri] == NULL)
				return ;
			ft_sp(s, str[stri], i, j);
			stri++;
		}
		if (is_separator(s[i], sep))
			j = i + 1;
		i++;
	}
}

char	**ft_split(char const *s, char *sep)
{
	char	**str;
	size_t	wc;
	size_t	i;

	if (s == NULL)
		return (0);
	wc = ft_word_count((char *)s, sep);
	str = (char **)malloc(sizeof(char *) * (wc + 1));
	if (str == NULL)
		return (0);
	ft_ss(s, sep, str);
	i = 0;
	while (i < wc)
	{
		if (str[i] == NULL)
		{
			ft_allfree(str);
			return (0);
		}
		i++;
	}
	str[wc] = 0;
	return (str);
}
