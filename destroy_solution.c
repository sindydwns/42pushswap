/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:36:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 04:44:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_solution(t_solution *solution)
{
	if (solution == NULL)
		return ;
	destroy_dequeue(solution->a);
	destroy_dequeue(solution->b);
	ft_lstclear(&(solution->cmdlst), NULL);
	free(solution);
}
