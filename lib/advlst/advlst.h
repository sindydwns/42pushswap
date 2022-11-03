/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 02:18:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVLST_H
# define ADVLST_H
# define CHAIN_FLAT 1
# define CHAIN_MAP 2
# define CHAIN_REDUCE 3
# define CHAIN_CURR 1
# define CHAIN_PREV 2
# define CHAIN_ALL 3
# define CONTENT_NO_FREE 0
# include "libft.h"

typedef void	(*t_delf)(void *p1);
typedef void	*(*t_cmp_f)(void *content, void *p2);
typedef struct s_lstb
{
	t_list			*list;
	t_list			*last;
	int				(*add)(struct s_lstb *b, void *content, t_delf del);
	struct s_lstb	*(*clear)(struct s_lstb *b, t_delf del);
}	t_lstb;

t_lstb	*lstb_init(t_lstb *lstb, t_list *list);
int		lstb_add(t_lstb *lstb, void *content, t_delf del);
t_lstb	*lstb_clear(t_lstb *lstb, t_delf del);
void	*lst_reduce(t_list *curr, t_cmp_f func, const void *init);
#endif