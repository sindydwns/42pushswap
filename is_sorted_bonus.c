/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:05:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 15:50:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
