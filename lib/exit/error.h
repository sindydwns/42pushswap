/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:31:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 01:39:30 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define HIDE_ERR 0
# define REPLACE_ERR 1
# define ERR "Error\n"
# define ERR_MALLOC "malloc fail"
# define ERR_OUT_OF_RANGE "out of range"
# define ERR_NOT_DEFINE_CASE "not define case"
# define ERR_OVERLAB "overlab"
# define NOT_EXIT 0
# define FORCE_EXIT 1

# include "libft.h"

void	error(char *msg, int force_exit);
t_list	*lstnew_guard(void *content);
void	*malloc_guard(size_t size);

#endif