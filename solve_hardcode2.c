/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hardcode2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:37 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/05 13:47:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

t_solution	*solve_hardcode2(t_solution *s)
{
	if (atop(s, 0) > abot(s, 0))
		sa(s);
	return (s);
}
