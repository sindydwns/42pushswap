/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:19:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*create_solution(t_dequeue *a, t_dequeue *b)
{
	t_solution	*ps;

	ps = ft_calloc(1, sizeof(t_solution));
	ps->a = a;
	ps->b = b;
	ps->elemsize = a->size + b->size;
	ps->sa = sa;
	ps->sb = sb;
	ps->ss = ss;
	ps->pa = pa;
	ps->pb = pb;
	ps->ra = ra;
	ps->rb = rb;
	ps->rr = rr;
	ps->rra = rra;
	ps->rrb = rrb;
	ps->rrr = rrr;
	return (ps);
}
