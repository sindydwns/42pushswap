/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:26:08 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 23:52:47 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*amax(t_solution *s)
{
	t_elem	*max;
	t_elem	*e;

	max = s->a->p[TOP];
	e = s->a->p[TOP];
	while (e)
	{
		if (max->rank < e->rank)
			max = e;
		e = e->down;
	}
	return (max);
}

t_elem	*amin(t_solution *s)
{
	t_elem	*min;
	t_elem	*e;

	min = s->a->p[TOP];
	e = s->a->p[TOP];
	while (e)
	{
		if (min->rank > e->rank)
			min = e;
		e = e->down;
	}
	return (min);
}

t_elem	*bmax(t_solution *s)
{
	t_elem	*max;
	t_elem	*e;

	max = s->b->p[TOP];
	e = s->b->p[TOP];
	while (e)
	{
		if (max->rank < e->rank)
			max = e;
		e = e->down;
	}
	return (max);
}

t_elem	*bmin(t_solution *s)
{
	t_elem	*min;
	t_elem	*e;

	min = s->b->p[TOP];
	e = s->b->p[TOP];
	while (e)
	{
		if (min->rank > e->rank)
			min = e;
		e = e->down;
	}
	return (min);
}
