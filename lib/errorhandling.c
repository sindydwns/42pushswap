/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:18:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/01 22:22:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	errorhandling(char *msg)
{
	if (DEBUG_MODE == 1)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd("Error\n", 2);
	exit(1);
}
