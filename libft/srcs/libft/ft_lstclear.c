/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:37:04 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:34:39 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last_lst;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		last_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = last_lst;
	}
	*lst = NULL;
}
