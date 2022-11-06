/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:26:08 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/05 14:21:31 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	amax(t_solution *s)
{
	int		max;
	t_elem	*e;

	max = FT_ERROR;
	e = s->a->p[TOP];
	while (e)
	{
		if (max < e->rank)
			max = e->rank;
		e = e->down;
	}
	return (max);
}

int	amin(t_solution *s)
{
	int		min;
	t_elem	*e;

	if (s->a->size == 0)
		return (FT_ERROR);
	min = s->a->p[TOP]->rank;
	e = s->a->p[TOP];
	while (e)
	{
		if (min > e->rank)
			min = e->rank;
		e = e->down;
	}
	return (min);
}

int	bmax(t_solution *s)
{
	int		max;
	t_elem	*e;

	max = FT_ERROR;
	e = s->b->p[TOP];
	while (e)
	{
		if (max < e->rank)
			max = e->rank;
		e = e->down;
	}
	return (max);
}

int	bmin(t_solution *s)
{
	int		min;
	t_elem	*e;

	if (s->b->size == 0)
		return (FT_ERROR);
	min = s->b->p[TOP]->rank;
	e = s->b->p[TOP];
	while (e)
	{
		if (min > e->rank)
			min = e->rank;
		e = e->down;
	}
	return (min);
}
