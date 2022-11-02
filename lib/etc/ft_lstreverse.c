/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:10:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 20:25:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list **lst)
{
	t_list	*next;
	t_list	*before;

	before = 0;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->next = before;
		before = *lst;
		*lst = next;
	}
	*lst = before;
	return (*lst);
}
