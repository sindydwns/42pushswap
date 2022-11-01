/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:06:50 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 19:01:27 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps_func	find_correct_instruction(const char *str)
{
	static const char		*cmdarr[] = {
		SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, NULL
	};
	static const t_ps_func	funcarr[] = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, NULL
	};
	int						idx;

	if (*str == '\n')
		return (FALSE);
	idx = 0;
	while (cmdarr[idx])
	{
		if (ft_strncmp(cmdarr[idx], str, ft_strlen(str) - 1) == 0)
			return (funcarr[idx]);
		idx++;
	}
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
		if (new == NULL || new->content == NULL)
			errorhandling("checker fail");
		free(cmd);
		ft_lstadd_back(&cmdlst, new);
		cmd = get_next_line(0);
	}
	return (cmdlst);
}

int	is_sorted(t_solution *ps)
{
	t_elem	*elem;

	if (ps->b->size > 0)
		return (FALSE);
	if (ps->elemsize != ps->a->size)
		return (FALSE);
	elem = ps->a->p[TOP];
	while (elem->down)
	{
		if (elem->rank >= elem->down->rank)
			return (FALSE);
		elem = elem->down;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	t_list	*intlst = parse_integer(argc - 1, argv + 1);
	t_solution *ps = solve(intlst, NULL);
	t_list	*cmdlst = parse_instruction();
	while (cmdlst)
	{
		((t_ps_func)cmdlst->content)(ps);
		cmdlst = cmdlst->next;
	}
	if (is_sorted(ps) == TRUE)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return 0;
}
