/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:49:49 by suhyun            #+#    #+#             */
/*   Updated: 2023/12/01 16:48:09 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_sign(char **s);
double	get_integer_part(char **s);
void	check_result(char *s);
void	get_decimal_part(char **s, double *decimal, double *d_sign);

double	ft_stod(char *s)
{
	double	result;
	double	sign;
	double	decimal;
	double	decimal_sign;

	result = 0;
	decimal = 0;
	decimal_sign = 1;
	sign = 1;
	check_result(s);
	sign = get_sign(&s);
	result = get_integer_part(&s);
	get_decimal_part(&s, &decimal, &decimal_sign);
	return (sign * (result + decimal / decimal_sign));
}

void	check_result(char *s)
{
	while (*s)
	{
		if (ft_strchr("-0123456789.", *s) == NULL)
			error_msg("not only digit\n");
		s++;
	}
}

double	get_sign(char **s)
{
	double	sign;

	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	return (sign);
}

double	get_integer_part(char **s)
{
	double	result;

	result = 0;
	while (**s && **s != '.')
	{
		result = result * 10 + (**s - '0');
		(*s)++;
	}
	return (result);
}

void	get_decimal_part(char **s, double *decimal, double *d_sign)
{
	if (**s == '.')
	{
		(*s)++;
		while (**s)
		{
			*decimal = *decimal * 10 + (**s - '0');
			*d_sign *= 10;
			(*s)++;
		}
	}
}
