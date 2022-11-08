/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_greedy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:59:47 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/08 22:36:52 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_GREEDY_H
# define SOLVE_GREEDY_H
# define GRA 0
# define GRB 1
# define GRRA 2
# define GRRB 3
# define GRA_RB 0
# define GRA_RRB 1
# define GRRA_RB 2
# define GRRA_RRB 3
# define GTOP 0
# define GBOT 1
# include "push_swap.h"

typedef struct s_greedy_cost
{
	int		cnt[4];
	int		cache[4];
	int		best;
	t_elem	*ea;
	t_elem	*eb;
}	t_greedy_cost;

#endif
