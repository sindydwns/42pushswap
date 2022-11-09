/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:24 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 15:52:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_dequeue *dq)
{
	t_elem	*elem1;
	t_elem	*elem2;

	if (dq == NULL || dq->size <= 1)
		return ;
	elem1 = dequeue(dq, TOP);
	elem2 = dequeue(dq, TOP);
	enqueue(dq, TOP, elem1);
	enqueue(dq, TOP, elem2);
}

t_solution	*sa(t_solution *ps)
{
	swap(ps->a);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(SA));
	ps->cmdsize++;
	return (ps);
}

t_solution	*sb(t_solution *ps)
{
	swap(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(SB));
	ps->cmdsize++;
	return (ps);
}

t_solution	*ss(t_solution *ps)
{
	swap(ps->a);
	swap(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(SS));
	ps->cmdsize++;
	return (ps);
}
