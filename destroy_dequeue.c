/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_dequeue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 04:35:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	destroy_dequeue(t_dequeue *dq)
{
	t_elem	*next;

	if (dq == NULL)
		return ;
	while (dq->p[TOP])
	{
		next = dq->p[TOP]->down;
		free(dq->p[TOP]);
		dq->p[TOP] = next;
	}
	free(dq);
}
