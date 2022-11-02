/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_guard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:58:51 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 00:01:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc_guard(size_t count, size_t size)
{
	void	*tmp;

	tmp = ft_calloc(count, size);
	if (tmp == 0)
		error(ERR_MALLOC, FORCE_EXIT);
	return (tmp);
}
