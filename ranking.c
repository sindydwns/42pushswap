/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 07:30:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_content(t_list *acc, t_list *cur)
{
	t_list		*node;
	t_list		*next;
	const int	cur_value = *(int *)(cur->content);

	if (acc == 0 || *(int *)(acc->content) > cur_value)
	{
		ft_lstadd_front(&acc, ft_lstnew_guard(cur->content));
		return (acc);
	}
	node = acc;
	while (node->next)
	{
		next = node->next;
		if (*(int *)(next->content) > cur_value)
		{
			node->next = ft_lstnew_guard(cur->content);
			node->next->next = next;
			return (acc);
		}
		node = next;
	}
	ft_lstadd_back(&node, ft_lstnew_guard(cur->content));
	return (acc);
}

t_list	*ranking(t_list *intlst)
{
	t_list	*lst;
	int		rank;

	lst = ft_lstreducer(intlst, (t_cmp_f)sort_content, NULL);
	rank = 0;
	while (lst)
	{
		*(int *)(lst->content) = ++rank;
		free(lst);
		lst = lst->next;
	}
	return (intlst);
}
