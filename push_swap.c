/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:30 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 14:45:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"
#include "advlst.h"

static t_solution	*find_best_solution(t_solution *acc, t_list *cur)
{
	if (acc == NULL)
		return ((t_solution *)cur->content);
	if ((t_solution *)cur->content == NULL)
		return (acc);
	if (acc->cmdsize > ((t_solution *)cur->content)->cmdsize)
		return ((t_solution *)cur->content);
	return (acc);
}

static void	print_cmd(char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putchar_fd('\n', 1);
}

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
	solutions = NULL;
	idx = -1;
	while (algorithms[++idx])
	{
		solution = solve(inputs, algorithms[idx]);
		ft_lstadd_front(&solutions, lstnew_guard(solution));
	}
	solution = lst_reduce(solutions, (t_cmp_f)find_best_solution, NULL);
	ft_lstiter(solution->cmdlst, (t_action_1)print_cmd);
	ft_lstclear(&inputs, NULL);
	ft_lstclear(&solutions, (t_action_1)destroy_solution);
}
