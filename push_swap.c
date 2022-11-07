/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 14:57:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"
#include "advlst.h"

static void	print_cmd(char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putchar_fd('\n', 1);
}

static t_list	*solve_all(const t_solve_f *algorithms, t_list *inputs)
{
	t_list			*solutions;
	t_solution		*solution;
	int				idx;

	solutions = NULL;
	idx = -1;
	while (algorithms[++idx])
	{
		solution = solve(inputs, algorithms[idx]);
		ft_lstadd_front(&solutions, lstnew_guard(solution));
	}
	return (solutions);
}

int	main(int argc, char *argv[])
{
	const t_solve_f	algorithms[] = {
		solve_hardcode2, solve_hardcode3, solve_hardcode4, solve_hardcode5,
		solve_sandglass1, solve_sandglass2,
		NULL
	};
	t_list			*inputs;
	t_list			*solutions;
	t_solution		*best_solution;

	if (argc == 1)
		return (0);
	inputs = ranking(parse_integer(argc - 1, argv + 1));
	if (inputs == NULL)
		error(ERR_NOT_DEFINE_CASE, FORCE_EXIT);
	solutions = solve_all(algorithms, inputs);
	best_solution = lst_reduce(solutions, (t_cmp_f)find_best_solution, NULL);
	if (best_solution)
		ft_lstiter(best_solution->cmdlst, (t_action_1)print_cmd);
	ft_lstclear(&inputs, NULL);
	ft_lstclear(&solutions, (t_action_1)destroy_solution);
	return (0);
}
