/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 19:08:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
