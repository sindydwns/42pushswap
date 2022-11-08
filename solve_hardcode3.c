/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hardcode3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 23:54:29 by yonshin          ###   ########.fr       */
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
	if (atop(s, 0) == max)
		ra(s);
	if (atop(s, 1) == max)
		rra(s);
	if (atop(s, 0) > atop(s, 1))
		sa(s);
	return (s);
}
