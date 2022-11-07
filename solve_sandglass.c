/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sandglass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 20:18:39 by yonshin          ###   ########.fr       */
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

static void	a_to_b(t_solution *s, int chunk)
{
	int	i;

	i = 1;
	while (s->a->size > 0)
	{
		chunk = s->a->size / 4;
		if (atop(s, 0) <= i + chunk)
		{
			pb(s);
			if (btop(s, 0) <= i)
				rb(s);
			i++;
		}
		else if (abot(s, 0) <= i + chunk)
		{
			rra(s)->pb(s);
			if (btop(s, 0) <= i)
				rb(s);
			i++;
		}
		else
			ra(s);
	}
}

static void	b_to_a(t_solution *s)
{
	int	max;
	int	direction;

	while (s->b->size != 0)
	{
		max = bmax(s);
		while (btop(s, 0) != max)
		{
			if (btop(s, 0) == max - 1)
				pa(s);
			direction = get_direction(s->b, max);
			if (direction > 0)
				rb(s);
			else if (direction < 0)
				rrb(s);
		}
		pa(s);
		if (s->a->size >= 2 && atop(s, 1) < atop(s, 0))
			sa(s);
	}
}

t_solution	*solve_sandglass(t_solution *s)
{
	t_solution	*copied;
	int			chunk;
	size_t		cmdsize;

	copied = create_solution(copy_dequeue(s->a), copy_dequeue(s->b));
	chunk = 0;
	a_to_b(copied, chunk);
	b_to_a(copied);
	cmdsize = 9999999;
	while (cmdsize > copied->cmdsize)
	{
		destroy_solution(copied);
		copied = create_solution(copy_dequeue(s->a), copy_dequeue(s->b));
		a_to_b(copied, ++chunk);
		b_to_a(copied);
		cmdsize = copied->cmdsize;
	}
	destroy_solution(copied);
	a_to_b(s, --chunk);
	b_to_a(s);
	return (s);
}
