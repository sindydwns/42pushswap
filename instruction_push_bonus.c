/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 15:51:41 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_dequeue *from, t_dequeue *to)
{
	t_elem	*elem;

	if (from == NULL || from->size == 0)
		return ;
	elem = dequeue(from, TOP);
	enqueue(to, TOP, elem);
}

t_solution	*pa(t_solution *ps)
{
	push(ps->b, ps->a);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(PA));
	ps->cmdsize++;
	return (ps);
}

t_solution	*pb(t_solution *ps)
{
	push(ps->a, ps->b);
	ft_lstadd_back(&(ps->cmdlst), ft_lstnew(PB));
	ps->cmdsize++;
	return (ps);
}
