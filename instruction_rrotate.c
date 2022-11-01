/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:20:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rrotate(t_dequeue *dq)
{
	t_elem	*elem;

	if (dq == NULL || dq->size <= 1)
		return ;
	elem = dequeue(dq, BOTTOM);
	enqueue(dq, TOP, elem);
}

t_solution	*rra(t_solution *ps)
{
	rrotate(ps->a);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RRA));
	ps->cmdsize++;
	return (ps);
}

t_solution	*rrb(t_solution *ps)
{
	rrotate(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RRB));
	ps->cmdsize++;
	return (ps);
}

t_solution	*rrr(t_solution *ps)
{
	rrotate(ps->a);
	rrotate(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RRR));
	ps->cmdsize++;
	return (ps);
}
