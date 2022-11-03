/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:13:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 03:33:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advlst.h"

t_lstb	*lstb_reduce(t_lstb *lstb, t_reduce_f func, t_list *init)
{
	lstb->prev = lstb->list;
	lstb->list = lst_reduce(lstb->list, (t_cmp_f)func, init);
	lstb->last = ft_lstlast(lstb->list);
	return (lstb);
}
