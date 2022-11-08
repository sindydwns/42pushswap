/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 23:54:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advlst.h"
#include "error.h"
#include "mymath.h"
#include "solve_greedy.h"

static t_greedy_cost	*create_greedy(t_solution *s, t_elem *eb, t_elem *amax)
{
	t_elem			*ea;
	t_greedy_cost	*gc;

	gc = ft_calloc(1, sizeof(t_greedy_cost));
	if (gc == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	gc->eb = eb;
	ea = s->a->p[GTOP];
	gc->ea = ea;
	while (ea)
	{
		if (amax->rank > eb->rank && ea->rank > eb->rank && ea->rank < gc->ea->rank)
			gc->ea = ea;
		if (amax->rank < eb->rank && ea->rank < gc->ea->rank)
			gc->ea = ea;
		ea = ea->down;
	}
	gc->cache[GRA] = elemcnt(gc->ea, GTOP);
	gc->cache[GRB] = elemcnt(gc->eb, GTOP);
	gc->cache[GRRA] = elemcnt(gc->ea, GBOT) + 1;
	gc->cache[GRRB] = elemcnt(gc->eb, GBOT) + 1;
	return (gc);
}

static t_greedy_cost	*get_best_gc(t_solution *s)
{
	const int		a_max = amax(s);
	t_greedy_cost	*res;
	t_greedy_cost	*gc;
	t_elem			*elem;

	res = NULL;
	elem = s->b->p[GBOT];
	while (elem)
	{
		gc = create_greedy(s, elem, a_max);
		gc->cnt[GRA_RB] = max(gc->cache[GRA], gc->cache[GRB]);
		gc->cnt[GRA_RRB] = gc->cache[GRA] + gc->cache[GRRB];
		gc->cnt[GRRA_RB] = gc->cache[GRRA] + gc->cache[GRB];
		gc->cnt[GRRA_RRB] = max(gc->cache[GRRA], gc->cache[GRRB]);
		gc->best = *arr_min(gc->cnt, 4);
		if (res == NULL || res->best > gc->best)
		{
			free(res);
			res = gc;
		}
		else
			free(gc);
		elem = elem->up;
	}
	return (res);
}

static void	greedy_rotate(t_solution *s, t_greedy_cost *gc)
{
	while (s->a->p[TOP] != gc->ea)
		ra(s);
	while (s->b->p[TOP] != gc->eb)
		rb(s);
}

t_solution	*solve_greedy(t_solution *s)
{
	t_greedy_cost	*gc;

	while (s->a->size > 0)
		pb(s);
	while (s->b->size > 0)
	{
		gc = get_best_gc(s);
		greedy_rotate(s, gc);
		pa(s);
		free(gc);
	}
	while (atop(s, 0) != amin(s)->rank)
		ra(s);
	return (s);
}
