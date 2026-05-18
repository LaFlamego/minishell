/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:55:09 by crevette          #+#    #+#             */
/*   Updated: 2026/05/18 23:18:28 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"
#include "libft.h"
#include <stdlib.h>

int	env_set_exit_code(unsigned int exit_code, t_env *env)
{
	t_string	var;
	char		*val;

	var = ft_string_from_cstring_alloc("?=");
	if (!var.content)
		return (1);
	val = ft_itoa(exit_code);
	if (!val)
	{
		free(var.content);
		return (1);
	}
	ft_string_push_str(&var, val);
	free(val);
	env_set(env, var.content);
	free(var.content);
	return (0);
}
