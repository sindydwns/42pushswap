/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:27 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/03 22:33:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_clear(t_lstb *lstb, t_delf content_del)
{
	ft_lstclear(&(lstb->list), content_del);
	lstb_init(lstb, NULL);
	return (lstb);
}
