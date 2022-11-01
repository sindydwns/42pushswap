/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_guard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:33:49 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 23:35:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_malloc_guard(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == 0)
		error(ERR_MALLOC, FORCE_EXIT);
	return (res);
}
