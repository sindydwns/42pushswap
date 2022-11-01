/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:18:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 22:56:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	error(char *msg, int force_exit)
{
	if (!HIDE_ERR)
	{
		if (REPLACE_ERR)
			ft_putstr_fd(ERR, 2);
		else
			ft_putstr_fd(msg, 2);
	}
	if (force_exit == FORCE_EXIT)
		exit(1);
}
