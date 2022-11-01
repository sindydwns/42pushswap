/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:20:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate(t_dequeue *dq)
{
	t_elem	*elem;

	if (dq == NULL || dq->size <= 1)
		return ;
	elem = dequeue(dq, TOP);
	enqueue(dq, BOTTOM, elem);
}

t_solution	*ra(t_solution *ps)
{
	rotate(ps->a);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RA));
	ps->cmdsize++;
	return (ps);
}

t_solution	*rb(t_solution *ps)
{
	rotate(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RB));
	ps->cmdsize++;
	return (ps);
}

t_solution	*rr(t_solution *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(RR));
	ps->cmdsize++;
	return (ps);
}
