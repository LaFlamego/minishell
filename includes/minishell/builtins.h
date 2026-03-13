/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:13:34 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 17:14:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int				mini_export(int argc, char *argv[], t_ctx *ctx);
int				mini_unset(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_exit(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_env(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_pwd(int argc, char *argv[], t_ctx *ctx);

#endif
