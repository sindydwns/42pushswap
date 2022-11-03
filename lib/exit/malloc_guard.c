/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_guard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:33:49 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 01:39:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"

void	*malloc_guard(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == 0)
		error(ERR_MALLOC, FORCE_EXIT);
	return (res);
}
