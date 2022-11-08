/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:26:08 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 00:13:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*atop(t_solution *s, size_t idx)
{
	t_elem	*e;

	if (s->a->size <= idx)
		return (0);
	e = s->a->p[TOP];
	while (idx--)
		e = e->down;
	return (e);
}

t_elem	*abot(t_solution *s, size_t idx)
{
	t_elem	*e;

	if (s->a->size <= idx)
		return (0);
	e = s->a->p[BOTTOM];
	while (idx--)
		e = e->up;
	return (e);
}

t_elem	*btop(t_solution *s, size_t idx)
{
	t_elem	*e;

	if (s->b->size <= idx)
		return (0);
	e = s->b->p[TOP];
	while (idx--)
		e = e->down;
	return (e);
}

t_elem	*bbot(t_solution *s, size_t idx)
{
	t_elem	*e;

	if (s->b->size <= idx)
		return (0);
	e = s->b->p[BOTTOM];
	while (idx--)
		e = e->up;
	return (e);
}
