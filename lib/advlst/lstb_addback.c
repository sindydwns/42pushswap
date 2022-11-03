/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:42:16 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 02:49:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_addback(t_lstb *lstb, t_list *node)
{
	if (lstb->last)
		ft_lstadd_back(&(lstb->last), node);
	else
		ft_lstadd_back(&(lstb->list), node);
	lstb->last = node;
	return (lstb);
}
