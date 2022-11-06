/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 01:13:30 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_solution	*solve(t_list *intlst, t_solve_f solve_func)
{
	t_solution	*res;

	if (solve_func == NULL)
		return (NULL);
	res = create_solution(create_dequeue(intlst), create_dequeue(NULL));
	if (is_sorted(res))
		return (res);
	if (solve_func(res) == NULL || is_sorted(res) == FALSE)
	{
		destroy_solution(res);
		return (NULL);
	}
	return (res);
}
