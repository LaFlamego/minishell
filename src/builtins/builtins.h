/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:13:34 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:52:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "src/ctx/ctx.h"

unsigned int	mini_echo(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_export(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_unset(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_exit(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_env(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_pwd(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_cd(int argc, char *argv[], t_ctx *ctx);

int				export_print_vars(t_ctx *ctx);
bool			export_is_valid_arg(char *arg);

#endif
