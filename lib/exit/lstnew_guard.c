/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_guard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:29:42 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 01:39:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

t_list	*lstnew_guard(void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == 0)
		error(ERR_MALLOC, FORCE_EXIT);
	return (node);
}
