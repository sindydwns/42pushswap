/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 22:59:38 by yonshin          ###   ########.fr       */
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
		error(ERR_MALLOC, FORCE_EXIT);
	b = create_dequeue(NULL);
	if (b == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	result = create_solution(a, b);
	if (result == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	if (solve_func != NULL)
		solve_func(result);
	return (result);
}
