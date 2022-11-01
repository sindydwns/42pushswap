/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 22:59:38 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	*find_next_min_node(t_list *intlst, const long prev_min)
{
	t_list	*res;
	long	next_min;
	int		cur_val;

	next_min = (long)INT_MAX + 1;
	while (intlst)
	{
		cur_val = *(int *)(intlst->content);
		if (prev_min < cur_val && cur_val < next_min)
		{
			next_min = cur_val;
			res = intlst;
		}
		intlst = intlst->next;
	}
	return ((int *)(res->content));
}

void	rank_integer(t_list *intlst)
{
	const int	size = ft_lstsize(intlst);
	t_list		*min_node;
	int			**ranklst;
	int			idx;

	ranklst = ft_calloc(size, sizeof(int *));
	if (ranklst == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	min_node = intlst;
	idx = 0;
	while (idx < size)
	{
		if (idx == 0)
			ranklst[idx] = find_next_min_node(intlst, (long)INT_MIN - 1);
		else
			ranklst[idx] = find_next_min_node(intlst, *(ranklst[idx - 1]));
		idx++;
	}
	idx = 0;
	while (idx < size)
	{
		*(ranklst[idx]) = idx + 1;
		idx++;
	}
	free(ranklst);
}
