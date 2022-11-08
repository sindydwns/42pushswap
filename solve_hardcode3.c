/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hardcode3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 00:00:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_solution	*solve_hardcode3(t_solution *s)
{
	int	max;

	if (s->a->size != 3)
		return (NULL);
	max = amax(s)->rank;
	if (atop(s, 0)->rank == max)
		ra(s);
	if (atop(s, 1)->rank == max)
		rra(s);
	if (atop(s, 0)->rank > atop(s, 1)->rank)
		sa(s);
	return (s);
}
