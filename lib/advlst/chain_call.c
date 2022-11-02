/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:39 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 08:11:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

static t_list	*flat_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	return (chain_apply(f, (*lst)->content, ch->param, ch->param_len));
}

static t_list	*map_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	void	*content;

	content = chain_apply(f, (*lst)->content, ch->param, ch->param_len);
	return (ft_lstnew_guard(content));
}

static t_list	*reduce_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	void	*content;

	content = chain_apply(f, lst, ch->param, ch->param_len);
	return (ft_lstnew_guard(content));
}

t_chain	*chain_call(t_chain *chain, int t, void *f, t_delf del)
{
	t_chain	*res;

	chain->next(chain);
	chain->freerule[0] = del;
	res = 0;
	if (t == CHAIN_MAP)
		res = chain_iterate(chain, map_factory, (t_mapf)f);
	if (t == CHAIN_FLAT)
		res = chain_iterate(chain, flat_factory, (t_mapf)f);
	if (t == CHAIN_REDUCE)
		res = chain_iterate(chain, reduce_factory, (t_mapf)f);
	chain_param0(chain);
	return (res);
}
