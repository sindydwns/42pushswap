/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:55:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 03:05:55 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_init(t_lstb *lstb, t_list *list)
{
	if (lstb == NULL)
		return (NULL);
	lstb->list = list;
	lstb->addback = lstb_addback;
	lstb->addfront = lstb_addfront;
	lstb->clear = lstb_clear;
	lstb->clear_prev = lstb_clear_prev;
	lstb->reduce = lstb_reduce;
	lstb->last = ft_lstlast(list);
	lstb->prev = NULL;
	return (lstb);
}
