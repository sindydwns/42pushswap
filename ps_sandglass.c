/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sandglass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:29:26 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_direction(t_dequeue *dq, int find)
{
	int		distance;
	t_elem	*upper;
	t_elem	*lower;

	if (dq->p[TOP]->rank == find)
		return (0);
	distance = 1;
	upper = dq->p[TOP]->down;
	lower = dq->p[BOTTOM];
	while ((upper->rank != find) && (lower->rank != find))
	{
		if (upper == NULL || lower == NULL)
			errorhandling("get direction failure");
		upper = upper->down;
		lower = lower->up;
		distance++;
	}
	if (find == upper->rank)
		return (distance);
	else
		return (-distance);
}

t_solution	*ps_sandglass(t_solution *ps)
{
	int	chunk;
	int	i;

	chunk = 30;
	i = 1;
	while (ps->a->size > 0)
	{
		if (ps->a->p[TOP]->rank < i + chunk)
		{
			pb(ps);
			if (ps->b->p[TOP]->rank < i)
				rb(ps);
			i++;
		}
		else
		{
			ra(ps);
		}
	}
	while (ps->b->size != 0)
	{
		while (ps->b->p[TOP]->rank != (int)ps->b->size)
		{
			if (get_direction(ps->b, ps->b->size) > 0)
				rb(ps);
			else
				rrb(ps);
		}
		pa(ps);
	}
	return (ps);
}
