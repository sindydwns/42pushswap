/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 14:19:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVLST_H
# define ADVLST_H
# define CONTENT_NO_FREE 0
# include "libft.h"

typedef void	(*t_delf)(void *p1);
typedef void	*(*t_cmp_f)(void *acc, void *cur);
typedef t_list	*(*t_reduce_f)(t_list *acc, t_list *cur);
typedef struct s_lstb
{
	t_list			*list;
	t_list			*last;
	t_list			*prev;
	struct s_lstb	*(*addback)(struct s_lstb *b, t_list *node);
	struct s_lstb	*(*addfront)(struct s_lstb *b, t_list *node);
	struct s_lstb	*(*reduce)(struct s_lstb *b, t_reduce_f func, t_list *init);
	struct s_lstb	*(*clear_prev)(struct s_lstb *b, t_delf del);
	struct s_lstb	*(*clear)(struct s_lstb *b, t_delf del);
}	t_lstb;

t_lstb	*lstb_init(t_lstb *lstb, t_list *list);
t_lstb	*lstb_addback(t_lstb *lstb, t_list *node);
t_lstb	*lstb_addfront(t_lstb *lstb, t_list *node);
t_lstb	*lstb_clear(t_lstb *lstb, t_delf del);
t_lstb	*lstb_clear_prev(t_lstb *lstb, t_delf del);
t_lstb	*lstb_reduce(t_lstb *lstb, t_reduce_f func, t_list *init);
void	*lst_reduce(t_list *curr, t_cmp_f func, void *init);
#endif