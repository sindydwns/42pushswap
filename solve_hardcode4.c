/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hardcode4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 00:00:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_solution	*solve_hardcode4(t_solution *s)
{
	int	min;

	if (s->a->size != 4)
		return (NULL);
	min = amin(s)->rank;
	if (atop(s, 1)->rank == min)
		ra(s);
	else if (atop(s, 2)->rank == min)
		ra(s)->ra(s);
	else if (atop(s, 3)->rank == min)
		rra(s);
	pb(s);
	solve_hardcode3(s);
	pa(s);
	return (s);
}
