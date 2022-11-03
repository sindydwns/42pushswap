/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 04:18:06 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"
#include "advlst.h"

int	main(int argc, char *argv[])
{
	const t_solve_f	algorithms[] = {
		ps_sandglass,
		NULL
	};
	t_list			*inputs;
	t_list			*solutions;
	t_solution		*solution;
	int				idx;

	if (argc == 1)
		return (0);
	inputs = ranking(parse_integer(argc - 1, argv + 1));
	idx = -1;
	while (algorithms[++idx])
	{
		solution = solve(inputs, algorithms[idx]);
		ft_lstadd_front(&solutions, ft_lstnew_guard(solution));
	}
	solution = find_best_soultion(solutions);
	print_solution(solution);
	ft_lstclear(&inputs, NULL);
	ft_lstclear(&solution, destroy_solution);
}
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
