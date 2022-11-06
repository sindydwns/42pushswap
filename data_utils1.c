/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:26:08 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/05 14:27:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atop(t_solution *s, size_t idx)
{
	t_elem	*e;

	if (s->a->size <= idx)
		return (FT_ERROR);
	e = s->a->p[TOP];
	while (idx--)
		e = e->down;
	return (e->rank);
}

int	abot(t_solution *s, size_t idx)
{
	t_elem	*e;
	
	if (s->a->size <= idx)
		return (FT_ERROR);
	e = s->a->p[BOTTOM];
	while (idx--)
		e = e->up;
	return (e->rank);
}

int	btop(t_solution *s, size_t idx)
{
	t_elem	*e;
	
	if (s->b->size <= idx)
		return (FT_ERROR);
	e = s->b->p[TOP];
	while (idx--)
		e = e->down;
	return (e->rank);
}

int	bbot(t_solution *s, size_t idx)
{
	t_elem	*e;
	
	if (s->b->size <= idx)
		return (FT_ERROR);
	e = s->b->p[BOTTOM];
	while (idx--)
		e = e->up;
	return (e->rank);
}


