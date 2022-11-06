/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 00:41:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "advlst.h"
#include "push_swap.h"

static t_list	*sort_content(t_list *acc, t_list *cur)
{
	t_list		*node;
	t_list		*next;
	const int	cur_value = *(int *)(cur->content);

	if (acc == 0 || *(int *)(acc->content) > cur_value)
	{
		ft_lstadd_front(&acc, lstnew_guard(cur->content));
		return (acc);
	}
	node = acc;
	while (node->next)
	{
		next = node->next;
		if (*(int *)(next->content) > cur_value)
		{
			node->next = lstnew_guard(cur->content);
			node->next->next = next;
			return (acc);
		}
		node = next;
	}
	ft_lstadd_back(&node, lstnew_guard(cur->content));
	return (acc);
}

t_list	*ranking(t_list *intlst)
{
	t_list	*lst;
	int		rank;
	t_list	*tmp;

	lst = lst_reduce(intlst, (t_cmp_f)sort_content, NULL);
	rank = 0;
	while (lst)
	{
		*(int *)(lst->content) = ++rank;
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (intlst);
}
