/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_addback_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 11:29:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

void	lstb_addback_cont(t_lstb *lstb, void *content)
{
	t_list	*node;

	node = ft_lstnew_guard(content);
	lstb_addback(lstb, node);
}
