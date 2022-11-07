/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:43:12 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 14:47:24 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_solution	*find_best_solution(t_solution *acc, t_list *cur)
{
	if (acc == NULL)
		return ((t_solution *)cur->content);
	if ((t_solution *)cur->content == NULL)
		return (acc);
	if (acc->cmdsize > ((t_solution *)cur->content)->cmdsize)
		return ((t_solution *)cur->content);
	return (acc);
}
