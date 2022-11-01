/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:10:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 01:14:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list **lst)
{
	t_list	*next;
	t_list	*before;

	before = FT_NULL;
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
