/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:13:34 by Oery              #+#    #+#             */
/*   Updated: 2026/03/17 16:33:25 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell/ctx.h"

unsigned int	mini_echo(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_export(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_unset(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_exit(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_env(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_pwd(int argc, char *argv[], t_ctx *ctx);
unsigned int	mini_cd(int argc, char *argv[], t_ctx *ctx);

#endif
