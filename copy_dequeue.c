/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dequeue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:36:32 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 20:15:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_dequeue	*copy_dequeue(t_dequeue *dq)
{
	t_dequeue	*res;
	t_elem		*elem;
	t_elem		*new;

	if (dq == NULL)
		return (NULL);
	res = ft_calloc(1, sizeof(t_dequeue));
	if (res == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	elem = dq->p[TOP];
	while (elem)
	{
		new = newelem(elem->rank);
		enqueue(res, BOTTOM, new);
		elem = elem->down;
	}
	return (res);
}
