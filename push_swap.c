/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 07:47:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "advlst.h"

int	main(int argc, char *argv[])
{
	t_list	*input;
	t_list	*algorithms;
	t_list	*next;
	t_chain	ch;

	if (argc == 1)
		return (0);
	input = ranking(parse_integer(argc - 1, argv + 1));
	ft_lstadd_front(&algorithms, ft_lstnew_guard(ps_sandglass));
	chain_init(&ch, algorithms, CONTENT_NO_FREE);
	chain_call($ch, );

	
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
