/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_addfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:46:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 03:30:43 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_addback(t_lstb *lstb, t_list *node)
{
	ft_lstadd_front(&(lstb->list), node);
	if (lstb->last == 0)
		lstb->last = node;
	return (lstb);
}
