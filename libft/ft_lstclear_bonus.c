/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:53:24 by junsepar          #+#    #+#             */
/*   Updated: 2022/11/29 19:53:26 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nod;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		nod = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = nod;
	}
}
