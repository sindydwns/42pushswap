/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:21:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 06:35:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_back(t_list **node, t_list *new)
{
	t_list	*tmp;

	if (new == 0)
		return ;
	if (*node == 0)
	{
		*node = new;
		return ;
	}
	tmp = (*node)->next;
	(*node)->next = new;
	ft_lstadd_back(&new, tmp);
}
