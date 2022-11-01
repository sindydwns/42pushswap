/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:35 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 22:59:38 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static int	ps_atoi(char *str)
{
	long	num;
	char	sign;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'\
			|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str++ - '0');
		if ((sign == 1 && num > (long)INT_MAX)
			|| (sign == -1 && num > -(long)INT_MIN))
			error(ERR_OUT_OF_RANGE, FORCE_EXIT);
	}
	return (sign * num);
}

static int	is_numstr(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static int	*str_to_int(char *str)
{
	int	*result;

	if (is_numstr(str) == FALSE)
		error(ERR_OUT_OF_RANGE, FORCE_EXIT);
	result = malloc(sizeof(int));
	if (result == NULL)
		error(ERR_MALLOC, FORCE_EXIT);
	*result = ps_atoi(str);
	return (result);
}

t_list	*parse_integer(int str_cnt, char *strs[])
{
	t_list	*res;
	char	**splited_str;
	t_list	*new_node;
	int		i;
	int		j;

	res = NULL;
	i = -1;
	while (++i < str_cnt)
	{
		splited_str = ft_split(strs[i], ' ');
		j = -1;
		while (splited_str[++j] != NULL)
		{
			new_node = ft_lstnew(str_to_int(splited_str[j]));
			if (ft_lstfind_first(res, new_node->content, sizeof(int)) != NULL)
				error(ERR_OVERLAB, FORCE_EXIT);
			ft_lstadd_back(&res, new_node);
			free(splited_str[j]);
		}
		free(splited_str);
	}
	return (res);
}
