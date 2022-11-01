/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvisit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:35:39 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 05:00:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstreducer(t_list *curr, t_cmp_f func, const void *init)
{
	void	*acc;

	acc = (void *)init;
	while (curr)
	{
		acc = func(acc, curr);
		curr = curr->next;
	}
	return (acc);
}
