/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 01:48:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_solution(t_solution *ps, int printcmd)
{
	int i = 0;
	t_elem *elem_a = ps->a->p[TOP];
	size_t size_a = ps->a->size;
	t_elem *elem_b = ps->b->p[TOP];
	size_t size_b = ps->b->size;
	printf("\ta\tb\n-------------------------------\n");
	while (size_a != 0 || size_b != 0) {
		if (size_a == size_b) {
			printf("%d:\t%d\t%d\n", i++, elem_a->rank, elem_b->rank);
			elem_a = elem_a->down;
			elem_b = elem_b->down;
			size_a--;
			size_b--;
		}
		else if(size_a > size_b) {
			printf("%d:\t%d\t\n", i++, elem_a->rank);
			elem_a = elem_a->down;
			size_a--;
		}
		else if(size_b > size_a) {
			printf("%d:\t\t%d\n", i++, elem_b->rank);
			elem_b = elem_b->down;
			size_b--;
		}
	}
	printf("\ntotal size: %zu\n", ps->elemsize);
	if (printcmd == TRUE)
	{
		t_node *cur = ps->cmdlst;
		int	i = 0;
		while (cur)
		{
			if (i % 10 == 0)
				printf("\n");
			printf("%s\t", (char *)(cur->content));
			cur = cur->next;
			i++;
		}
		printf("\ncommand size: %zu\n", ps->cmdsize);
	}
}

void	dequeue_test()
{
	t_dequeue *a = ft_calloc(1, sizeof(t_dequeue));
	t_dequeue *b = ft_calloc(1, sizeof(t_dequeue));

	enqueue(a, TOP, newelem(5));
	enqueue(a, TOP, newelem(4));
	// enqueue(a, TOP, newelem(3));
	// enqueue(a, TOP, newelem(2));
	// enqueue(a, TOP, newelem(1));
	// enqueue(b, TOP, newelem(10));
	enqueue(b, TOP, newelem(9));
	// enqueue(b, TOP, newelem(8));
	// enqueue(b, TOP, newelem(7));
	// enqueue(b, TOP, newelem(6));

	// swap(a);
	// push(b, a);
	// rotate(a, TRUE);

}

void set_data_preset1(t_dequeue *a, t_dequeue *b)
{
	enqueue(a, TOP, newelem(5));
	enqueue(a, TOP, newelem(4));
	enqueue(a, TOP, newelem(3));
	enqueue(a, TOP, newelem(2));
	enqueue(a, TOP, newelem(1));

	enqueue(b, TOP, newelem(10));
	enqueue(b, TOP, newelem(9));
	enqueue(b, TOP, newelem(8));
	enqueue(b, TOP, newelem(7));
	enqueue(b, TOP, newelem(6));
}

void test_instruction()
{
	t_dequeue *a = ft_calloc(1, sizeof(t_dequeue));
	t_dequeue *b = ft_calloc(1, sizeof(t_dequeue));

	set_data_preset1(a, b);
	// dequeue(a, TOP);

	t_solution *ps = create_solution(a, b);

	pa(ps)->pa(ps)->pa(ps)->pa(ps)->pa(ps)->pa(ps)->pa(ps);
	pb(ps)->pb(ps)->pb(ps)->pb(ps)->pb(ps);
	sa(ps)->sb(ps)->ss(ps);
	ra(ps)->rra(ps)->rb(ps)->rrb(ps)->rr(ps)->rrr(ps);

	print_solution(ps, TRUE);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return 0;
	t_node	*intlst = parse_integer(argc - 1, argv + 1);
	rank_integer(intlst);
	t_solution *solution = solve(intlst, ps_sandglass);
	print_solution(solution, TRUE);
}
