/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:55:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 20:26:06 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_init(t_lstb *lstb, t_list *list)
{
	if (lstb == 0)
		return (0);
	lstb->list = list;
	lstb->add = lstb_add;
	lstb->clear = lstb_clear;
	lstb->last = list;
	while (lstb->last && lstb->last->next)
		lstb->last = lstb->last->next;
	return (lstb);
}
