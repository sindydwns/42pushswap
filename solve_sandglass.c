/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sandglass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 17:09:31 by yonshin          ###   ########.fr       */
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

static void	a_to_b(t_solution *solution)
{
	int	chunk;
	int	i;

	chunk = 30;
	i = 1;
	while (solution->a->size > 0)
	{
		if (solution->a->p[TOP]->rank < i + chunk)
		{
			pb(solution);
			if (solution->b->p[TOP]->rank < i)
				rb(solution);
			i++;
		}
		else
		{
			ra(solution);
		}
	}
}

static void	b_to_a(t_solution *solution)
{
	while (solution->b->size != 0)
	{
		while (solution->b->p[TOP]->rank != (int)solution->b->size)
		{
			if (get_direction(solution->b, solution->b->size) > 0)
				rb(solution);
			else
				rrb(solution);
		}
		pa(solution);
	}
}

t_solution	*solve_sandglass(t_solution *solution)
{
	a_to_b(solution);
	b_to_a(solution);
	return (solution);
}
