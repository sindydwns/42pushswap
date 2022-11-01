/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:27 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 20:26:06 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_clear(t_lstb *lstb, t_delf content_del)
{
	ft_lstclear(&(lstb->list), content_del);
	lstb_init(lstb, 0);
	return (lstb);
}
