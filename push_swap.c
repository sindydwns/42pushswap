/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:08:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 1)
		return 0;
	t_node	*intlst = parse_integer(argc - 1, argv + 1);
	// TODO: intlst 중복된 값 체크

	// int i = 1;
	// while (intlst != NULL) {
	// 	int *value = (int *)(intlst->content);
	// 	printf("%d:\t%d\n", i, *value);
	// 	intlst = intlst->next;
	// 	i++;
	// }
	
	rank_integer(intlst);
	// int i = 1;
	// while (intlst != NULL) {
	// 	int *value = (int *)(intlst->content);
	// 	printf("%d:\t%d\n", i, *value);
	// 	intlst = intlst->next;
	// 	i++;
	// }

	// const t_ps_func algorithm[] = {
	// 	ps_sandglass,
	// 	ps_triangle_merge
	// };
	// int i;
	// t_solution *result[3];

	// i = 0;
	// while (i < 3) {
	// 	result[i] = solve(intlst, algorithm[i]);
	// 	i++;
	// }
	// print_cmdlst(find_best_soultion(result, i)->cmdlst);
	// free(intlst);
	// freeAll(result, i);
}

// 어떤 일련된 작업을 이름을 붙여 작업 단위를 나눈다.

