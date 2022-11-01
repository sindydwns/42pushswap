/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:08:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution *solve(t_node *intlst, t_ps_func solve_func)
{
	t_dequeue *a;
	t_dequeue *b;
	t_solution *result;

	a = create_dequeue(intlst);
	if (a == NULL)
		errorhandling("solve.c: malloc fail");
	b = create_dequeue(NULL);
	if (b == NULL)
		errorhandling("solve.c: malloc fail");
	result = create_solution(a, b);
	if (result == NULL)
		errorhandling("solve.c: malloc fail");
	if (solve_func != NULL)
		solve_func(result);
	return (result);
}

