/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dequeue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:00 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:07:02 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dequeue	*create_dequeue(t_node *intlst)
{
	t_dequeue	*res;
	t_elem		*new;
	
	res = ft_calloc(1, sizeof(t_dequeue));
	if (res == NULL)
		errorhandling("malloc fail");
	while (intlst)
	{
		new = newelem(*((int *)(intlst->content)));
		enqueue(res, BOTTOM, new);
		intlst = intlst->next;
	}
	return (res);
}
