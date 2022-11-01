/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 00:54:43 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*input;
	t_list	*rank;
	t_list	*algorithms;

	if (argc == 1)
		return (0);
	input = parse_integer(argc - 1, argv + 1);
	rank = rank_integer(input);
	ft_lstadd_front(&algorithms, ft_lstnew_guard(ps_sandglass));
	// ft_lstadd_front(&algorithms, ft_lstnew_guard(ps_triangle_merge));
	

	// int i;
	// t_solution *result[3];

	// i = 0;
	// while (i < 3) {
	// 	result[i] = solve(input, algorithm[i]);
	// 	i++;
	// }
	// print_cmdlst(find_best_soultion(result, i)->cmdlst);
	// free(input);
	// freeAll(result, i);
}

// 어떤 일련된 작업을 이름을 붙여 작업 단위를 나눈다.

