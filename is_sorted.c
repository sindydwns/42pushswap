/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:05:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 16:05:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_solution *ps)
{
	t_elem	*elem;

	if (ps->b->size > 0)
		return (FALSE);
	if (ps->elemsize != ps->a->size)
		return (FALSE);
	elem = ps->a->p[TOP];
	while (elem->down)
	{
		if (elem->rank >= elem->down->rank)
			return (FALSE);
		elem = elem->down;
	}
	return (TRUE);
}