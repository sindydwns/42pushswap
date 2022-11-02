/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 08:22:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

void	lstb_addback(t_lstb *lstb, t_list *node)
{
	if (node == 0)
		return ;
	if (lstb->last)
		ft_lstadd_back(&(lstb->last), node);
	else
		ft_lstadd_back(&(lstb->list), node);
	lstb->last = ft_lstlast(node);
}
