/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 17:27:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_solution	*solve(t_list *intlst, t_solve_f solve_func)
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_solution	*solution;
	t_solution	*res;

	a = create_dequeue(intlst);
	if (a == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	b = create_dequeue(NULL);
	if (b == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	solution = create_solution(a, b);
	if (solution == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	if (is_sorted(solution))
		return (solution);
	if (solve_func != NULL)
		res = solve_func(solution);
	if (res == NULL)
		destroy_solution(solution);
	return (res);
}
