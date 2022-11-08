/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:20:07 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 22:37:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*arr_max(int *arr, int len)
{
	int	*max;

	if (arr == 0 || len <= 0)
		return (0);
	max = arr;
	while (len-- > 0)
		if (*max <= arr[len])
			max = arr + len;
	return (max);
}
