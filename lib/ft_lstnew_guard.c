/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_guard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:29:42 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 23:33:14 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew_guard(void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == 0)
		error(ERR_MALLOC, FORCE_EXIT);
	return (node);
}
