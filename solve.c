/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 20:52:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*solve(t_list *intlst, t_ps_func solve_func)
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_solution	*result;

	a = create_dequeue(intlst);
	if (a == NULL)
		errorhandling(ERR_MALLOC);
	b = create_dequeue(NULL);
	if (b == NULL)
		errorhandling(ERR_MALLOC);
	result = create_solution(a, b);
	if (result == NULL)
		errorhandling(ERR_MALLOC);
	if (solve_func != NULL)
		solve_func(result);
	return (result);
}
