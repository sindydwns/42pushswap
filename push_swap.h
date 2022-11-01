/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:46 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 06:57:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TOP 0
# define BOTTOM 1
# define SUCCESS 0
# define FAILURE 1
# define TRUE	1
# define FALSE	0
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define OK "OK\n"
# define KO "KO\n"
# include <stdlib.h>
# include "libft.h"

typedef struct s_elem
{
	int				rank;
	struct s_elem	*up;
	struct s_elem	*down;
}	t_elem;

typedef struct s_dequeue
{
	size_t		size;
	t_elem		*p[2];
}	t_dequeue;

typedef struct s_solution
{
	t_dequeue			*a;
	t_dequeue			*b;
	size_t				elemsize;
	struct s_solution	*(*sa)(struct s_solution *ps);
	struct s_solution	*(*sb)(struct s_solution *ps);
	struct s_solution	*(*ss)(struct s_solution *ps);
	struct s_solution	*(*pa)(struct s_solution *ps);
	struct s_solution	*(*pb)(struct s_solution *ps);
	struct s_solution	*(*ra)(struct s_solution *ps);
	struct s_solution	*(*rb)(struct s_solution *ps);
	struct s_solution	*(*rr)(struct s_solution *ps);
	struct s_solution	*(*rra)(struct s_solution *ps);
	struct s_solution	*(*rrb)(struct s_solution *ps);
	struct s_solution	*(*rrr)(struct s_solution *ps);
	t_list				*cmdlst;
	size_t				cmdsize;
}	t_solution;

typedef t_solution	*(*t_ps_func)(t_solution *ps);

t_list		*parse_integer(int str_cnt, char *strs[]);
void		ranking(t_list *intlst);
t_solution	*solve(t_list *intlst, t_ps_func func);
t_solution	*find_best_soultion(t_solution *soln_arr, int soln_cnt);
t_dequeue	*create_dequeue(t_list *intlst);
void		destroy_dequeue(t_dequeue *dq);

t_solution	*ps_sandglass(t_solution *ps);
t_solution	*ps_triangle_merge(t_solution *ps);
void		enqueue(t_dequeue *dq, int edge, t_elem *new);
t_elem		*dequeue(t_dequeue *dq, int edge);
t_elem		*newelem(int rank);

t_solution	*sa(t_solution *ps);
t_solution	*sb(t_solution *ps);
t_solution	*ss(t_solution *ps);
t_solution	*pa(t_solution *ps);
t_solution	*pb(t_solution *ps);
t_solution	*ra(t_solution *ps);
t_solution	*rb(t_solution *ps);
t_solution	*rr(t_solution *ps);
t_solution	*rra(t_solution *ps);
t_solution	*rrb(t_solution *ps);
t_solution	*rrr(t_solution *ps);
t_solution	*create_solution(t_dequeue *a, t_dequeue *b);

#endif
