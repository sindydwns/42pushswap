/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_clear_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:01:05 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 03:01:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_clear_prev(t_lstb *lstb, t_delf content_del)
{
	ft_lstclear(&(lstb->prev), content_del);
	return (lstb);
}