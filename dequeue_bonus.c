/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 15:50:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "error.h"
#include "push_swap_bonus.h"

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

int	elemcnt(t_elem *elem, int direction)
{
	int	cnt;

	cnt = 0;
	if (elem == NULL)
		return (cnt);
	while (direction == TOP && elem->up)
	{
		cnt++;
		elem = elem->up;
	}
	while (direction == BOTTOM && elem->down)
	{
		cnt++;
		elem = elem->down;
	}
	return (cnt);
}

t_elem	*newelem(int rank)
{
	t_elem	*elem;

	elem = ft_calloc(1, sizeof(t_elem));
	if (elem == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	elem->rank = rank;
	return (elem);
}
