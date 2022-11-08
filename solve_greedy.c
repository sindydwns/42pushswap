/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 01:49:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advlst.h"
#include "error.h"
#include "mymath.h"
#include "solve_greedy.h"

static t_greedy_cost	*create_greedy(t_solution *s, t_elem *eb)
{
	t_elem			*ea;
	t_greedy_cost	*gc;

	gc = ft_calloc(1, sizeof(t_greedy_cost));
	if (gc == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	gc->eb = eb;
	ea = s->a->p[GTOP];
	gc->ea = amax(s);
	while (ea)
	{
		if (ea->rank > eb->rank && ea->rank < gc->ea->rank)
			gc->ea = ea;
		ea = ea->down;
	}
	if (gc->ea && gc->ea->rank < eb->rank)
		gc->ea = amin(s);
	gc->n[GRA] = elemcnt(gc->ea, GTOP);
	gc->n[GRB] = elemcnt(gc->eb, GTOP);
	gc->n[GRRA] = elemcnt(gc->ea, GBOT) + 1;
	gc->n[GRRB] = elemcnt(gc->eb, GBOT) + 1;
	return (gc);
}

static t_greedy_cost	*get_best_gc(t_solution *s)
{
	t_greedy_cost	*res;
	t_greedy_cost	*gc;
	t_elem			*elem;

	res = NULL;
	elem = s->b->p[GBOT];
	while (elem)
	{
		gc = create_greedy(s, elem);
		gc->mth[GRA_RB] = max(gc->n[GRA], gc->n[GRB]);
		gc->mth[GRA_RRB] = gc->n[GRA] + gc->n[GRRB];
		gc->mth[GRRA_RB] = gc->n[GRRA] + gc->n[GRB];
		gc->mth[GRRA_RRB] = max(gc->n[GRRA], gc->n[GRRB]);
		gc->best = *arr_min(gc->mth, 4);
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
	gc->best_mth = GRA_RB;
	if (gc->best == gc->mth[GRA_RRB])
		gc->best_mth = GRA_RRB;
	if (gc->best == gc->mth[GRRA_RB])
		gc->best_mth = GRRA_RB;
	if (gc->best == gc->mth[GRRA_RRB])
		gc->best_mth = GRRA_RRB;
	if (gc->best_mth == GRA_RB)
		while (gc->n[GRB] > 0 && gc->n[GRA]-- > 0 && gc->n[GRB]--)
			rr(s);
	if (gc->best_mth == GRRA_RRB)
		while (gc->n[GRRB] > 0 && gc->n[GRRA]-- > 0 && gc->n[GRRB]--)
			rrr(s);
	if (gc->best_mth == GRA_RB || gc->best_mth == GRA_RRB)
		while (gc->n[GRA]-- > 0)
			ra(s);
	if (gc->best_mth == GRA_RB || gc->best_mth == GRRA_RB)
		while (gc->n[GRB]-- > 0)
			rb(s);
	if (gc->best_mth == GRA_RRB || gc->best_mth == GRRA_RRB)
		while (gc->n[GRRB]-- > 0)
			rrb(s);
	if (gc->best_mth == GRRA_RB || gc->best_mth == GRRA_RRB)
		while (gc->n[GRRA]-- > 0)
			rra(s);
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
	while (atop(s, 0)->rank != amin(s)->rank)
		ra(s);
	return (s);
}
