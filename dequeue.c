/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:16:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	enqueue(t_dequeue *dq, int edge, t_elem *new)
{
	if (edge != TOP && edge != BOTTOM)
		return ;
	if (dq->size == 0)
	{
		dq->p[TOP] = new;
		dq->p[BOTTOM] = new;
		dq->size++;
		return ;
	}
	if (edge == TOP)
	{
		dq->p[TOP]->up = new;
		new->down = dq->p[TOP];
	}
	else
	{
		dq->p[BOTTOM]->down = new;
		new->up = dq->p[BOTTOM];
	}
	dq->size++;
	dq->p[edge] = new;
}

t_elem	*dequeue(t_dequeue *dq, int edge)
{
	t_elem	*result;

	if ((edge != TOP && edge != BOTTOM) || (dq->size == 0))
		return (NULL);
	result = dq->p[edge];
	if (dq->size == 1)
		ft_memset(dq, 0, sizeof(t_dequeue));
	else if (edge == TOP)
	{
		dq->p[TOP] = result->down;
		result->down->up = NULL;
		dq->size--;
	}
	else
	{
		dq->p[BOTTOM] = result->up;
		result->up->down = NULL;
		dq->size--;
	}
	result->down = NULL;
	result->up = NULL;
	return (result);
}

t_elem	*newelem(int rank)
{
	t_elem	*elem;

	elem = ft_calloc(1, sizeof(t_elem));
	elem->rank = rank;
	return (elem);
}
