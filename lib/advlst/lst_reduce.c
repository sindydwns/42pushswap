/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:13:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 01:50:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advlst.h"

void	*lst_reduce(t_list *curr, t_cmp_f func, const void *init)
{
	void	*acc;

	acc = (void *)init;
	while (curr)
	{
		acc = func(acc, curr);
		curr = curr->next;
	}
	return (acc);
}