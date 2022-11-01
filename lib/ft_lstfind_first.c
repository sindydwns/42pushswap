/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:35:39 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 23:11:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_first(t_list *lst, void *content, size_t size)
{
	while (lst)
	{
		if (ft_memcmp(lst->content, content, size) == 0)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
