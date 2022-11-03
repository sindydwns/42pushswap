/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:44:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 04:48:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*find_best_solution(t_list *solution)
{
	t_list	*best;
	int		best_cmd_size;
	int		curr_cmd_size;

	if (solution == NULL)
		return ;
	best = solution;
	while (solution)
	{
		best_cmd_size = ((t_solution *)best->content)->cmdsize;
		curr_cmd_size = ((t_solution *)solution->content)->cmdsize;
		if (best_cmd_size > curr_cmd_size)
		solution = solution->next;
	}
}
