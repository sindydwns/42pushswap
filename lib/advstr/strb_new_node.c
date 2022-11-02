/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:51:55 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 19:52:58 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

t_list	*strb_new_node(char *str, t_del del)
{
	t_substr	*substr;
	t_list		*node;

	if (str == 0)
		return (0);
	substr = strb_create_substr(str, ft_strlen(str), del);
	if (substr == 0)
		return (0);
	node = ft_lstnew(substr);
	if (node == 0)
	{
		free(substr);
		if (del)
			del(str);
	}
	return (node);
}
