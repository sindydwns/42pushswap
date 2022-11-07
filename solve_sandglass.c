/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sandglass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 12:43:21 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
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
			error(ERR_NOT_DEFINE_CASE, FORCE_EXIT);
		upper = upper->down;
		lower = lower->up;
		distance++;
	}
	if (find == upper->rank)
		return (distance);
	else
		return (-distance);
}

static void	a_to_b(t_solution *s, int mod)
{
	int	chunk;
	int	i;

	chunk = 15;
	i = 1;
	while (s->a->size > 0)
	{
		if (atop(s, 0) < i + chunk)
		{
			pb(s);
			if (btop(s, 0) < i)
				rb(s);
			i++;
		}
		else
		{
			if (mod && s->a->size < s->b->size)
				rra(s);
			else
				ra(s);
		}
	}
}

static void	b_to_a(t_solution *s)
{
	int	max;
	int	distance;

	while (s->b->size != 0)
	{
		max = bmax(s);
		while (btop(s, 0) != max)
		{
			if (btop(s, 0) == max - 1)
				pa(s);
			distance = get_direction(s->b, max);
			if (distance > 0)
				rb(s);
			else if (distance < 0)
				rrb(s);
		}
		pa(s);
		if (s->a->size >= 2 && atop(s, 1) < atop(s, 0))
			sa(s);
	}
}

t_solution	*solve_sandglass1(t_solution *s)
{
	a_to_b(s, FALSE);
	b_to_a(s);
	return (s);
}

t_solution	*solve_sandglass2(t_solution *s)
{
	a_to_b(s, TRUE);
	b_to_a(s);
	return (s);
}
