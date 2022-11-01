/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:35 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 17:22:13 by yonshin          ###   ########.fr       */
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
			errorhandling("out of integer range");
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

static int	*splited_str_to_int(char *str)
{
	int	*result;

	if (is_numstr(str) == FALSE)
		errorhandling("input is not a number");
	result = malloc(sizeof(int));
	if (result == NULL)
		errorhandling("malloc failure");
	*result = ps_atoi(str);
	return (result);
}

static int	check_duplicate(t_node *intlst, int *needle)
{
	while (intlst)
	{
		if (*((int *)intlst->content) == *needle)
			return (FALSE);
		intlst = intlst->next;
	}
	return (TRUE);
}

t_node	*parse_integer(int str_cnt, char *strs[])
{
	t_node	*intlst;
	char	**splited_str;
	int		i;
	int		j;
	t_node	*new_node;

	intlst = NULL;
	i = 0;
	while (i < str_cnt)
	{
		splited_str = ft_split(strs[i], ' ');
		j = 0;
		while (splited_str[j] != NULL)
		{
			new_node = ft_lstnew(splited_str_to_int(splited_str[j]));
			if (check_duplicate(intlst, new_node->content) == FALSE)
				errorhandling("duplicated number");
			ft_lstadd_back(&intlst, new_node);
			free(splited_str[j]);
			j++;
		}
		i++;
		free(splited_str);
	}
	return (intlst);
}
