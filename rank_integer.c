/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 06:47:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort(t_list *acc, t_list *cur)
{
	t_list	*node;

	node = acc;
	while (node)
	{
		if (*(int *)(node->content) < *(int *)(cur->content))
		node = node->next;
	}
	return (acc);
}

void	rank_integer(t_list *intlst)
{
	t_list		*lst;
	
	lst = NULL;
	lst = ft_lstreducer(intlst, (t_cmp_f)sort, NULL);
	return (lst);
}
