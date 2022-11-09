/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dequeue_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:00 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/09 15:50:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap_bonus.h"

t_dequeue	*create_dequeue(t_list *intlst)
{
	t_dequeue	*res;
	t_elem		*new;

	res = ft_calloc(1, sizeof(t_dequeue));
	if (res == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	while (intlst)
	{
		new = newelem(*((int *)(intlst->content)));
		enqueue(res, BOTTOM, new);
		intlst = intlst->next;
	}
	return (res);
}
