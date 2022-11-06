/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:06:50 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/07 01:13:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include "get_next_line.h"

static t_solve_f	find_correct_instruction(const char *str)
{
	static const char		*cmdarr[] = {
		SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, NULL
	};
	static const t_solve_f	funcarr[] = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, NULL
	};
	int						idx;

	if (*str == '\n')
		error(ERR_NOT_DEFINE_CASE, FORCE_EXIT);
	idx = -1;
	while (cmdarr[++idx])
		if (ft_strncmp(cmdarr[idx], str, ft_strlen(str) - 1) == 0)
			return (funcarr[idx]);
	error(ERR_NOT_DEFINE_CASE, FORCE_EXIT);
	return (NULL);
}

t_list	*parse_instruction(void)
{
	t_list		*cmdlst;
	t_list		*new;
	char		*cmd;

	cmdlst = NULL;
	cmd = get_next_line(0);
	while (cmd)
	{
		new = ft_lstnew(find_correct_instruction(cmd));
		if (new == NULL)
			error(ERR_MALLOC, FORCE_EXIT);
		free(cmd);
		ft_lstadd_back(&cmdlst, new);
		cmd = get_next_line(0);
	}
	return (cmdlst);
}

int	main(int argc, char *argv[])
{
	t_list		*intlst;
	t_solution	*ps;
	t_list		*cmdlst;

	if (argc == 1)
		return (0);
	intlst = parse_integer(argc - 1, argv + 1);
	ps = create_solution(create_dequeue(intlst), create_dequeue(NULL));
	cmdlst = parse_instruction();
	while (cmdlst)
	{
		((t_solve_f)cmdlst->content)(ps);
		cmdlst = cmdlst->next;
	}
	if (is_sorted(ps) == TRUE)
		ft_putstr_fd(OK, 1);
	else
		ft_putstr_fd(KO, 1);
	return (0);
}
