/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_triangle_merge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 23:53:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define NORMAL 1
#define REVERSE -1
typedef struct s_group {
	int	size;
	int	order;
} t_group;

static t_list	*split(t_group *s)
{

	// 연결리스트를 받아서 split을 한번 하고 연결리스트 형태로 다시 반환

}

static int	check_group_size(t_list *lst)
{
	const int	limit = 6;

	while (lst)
	{
		if (((t_group *)(lst->content))->size >= limit)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

// 시작 패턴 구하기
t_group	*step1(int elemsize)
{
	int	split_cnt;
	int	max;
	int	arr_len;
	t_group	*arr;

	split_cnt = 0;
	max = elemsize;
	while (max >= 6)
	{
		max = (elemsize / 3) + (elemsize - (elemsize / 3) * 3);
		split_cnt++;
	}
	arr_len = 1;
	while (split_cnt-- > 0)
		arr_len *= 3;
	arr = ft_calloc(arr_len, sizeof(t_group));
	
	// elemsize 값을 토대로 몇번 split할 것인지를 결정하기
		// 근데 한 그룹의 원소 개수가 무조건 6 미만이어야하기 때문에 이 값이 정확치 않음.
		// 결국 모든 그룹의 원소 개수가 6 미만으로 떨어질때까지 split을 반복해야함 (매 반복마다 조건문으로 확인)
	
}

// 구한 패턴대로 나누기
void	step2(t_solution *ps)
{

}

void	step3(t_solution *ps)
{
	step3_1(ps);
	step3_2(ps);
}

void	step3_1(t_solution *ps)
{

}

void	step3_2(t_solution *ps)
{

}

t_solution	*ps_triangle_merge(t_solution *ps)
{
	step1(ps);
	step2(ps);
	step3(ps);
	return NULL;
}
