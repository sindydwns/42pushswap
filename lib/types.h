/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:46:12 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 04:54:39 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef void	(*t_delf)(void *p1);
typedef t_list	*(*t_flatf)(void *content);
typedef t_list	*(*t_flatf1)(void *content);
typedef t_list	*(*t_flatf2)(void *content, void *p2);
typedef t_list	*(*t_flatf3)(void *content, void *p2, void *p3);
typedef t_list	*(*t_flatf4)(void *content, void *p2, void *p3, void *p4);
typedef void	*(*t_reducef)(t_list **list);
typedef void	*(*t_reducef1)(t_list **list);
typedef void	*(*t_reducef2)(t_list **list, void *p2);
typedef void	*(*t_reducef3)(t_list **list, void *p2, void *p3);
typedef void	*(*t_reducef4)(t_list **list, void *p2, void *p3, void *p4);
typedef void	*(*t_mapf)(void *content);
typedef void	*(*t_mapf1)(void *content);
typedef void	*(*t_mapf2)(void *content, void *p2);
typedef void	*(*t_mapf3)(void *content, void *p2, void *p3);
typedef void	*(*t_mapf4)(void *content, void *p2, void *p3, void *p4);
typedef t_mapf2	t_cmp_f;

#endif
