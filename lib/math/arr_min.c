/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:32:22 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 22:37:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*arr_min(int *arr, int len)
{
	int	*min;

	if (arr == 0 || len <= 0)
		return (0);
	min = arr;
	while (len-- > 0)
		if (*min >= arr[len])
			min = arr + len;
	return (min);
}
