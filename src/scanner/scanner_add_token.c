/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_add_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:45:40 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 16:28:38 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"
#include "./token/token.h"
#include <stdlib.h>

static t_list	*token_new_list(t_token_type type, char *text)
{
	t_token	*token;
	t_list	*lst;

	token = token_new(type, text);
	if (!token)
		return (NULL);
	lst = ft_lstnew(token);
	if (!lst)
	{
		token_free(token);
		return (NULL);
	}
	return (lst);
}

t_token	*scanner_add_token(t_scanner *s, t_token_type type)
{
	t_list	*lst;

	lst = token_new_list(type, NULL);
	if (!lst)
		return (NULL);
	ft_lstadd_back(&s->tokens, lst);
	return (lst->content);
}

t_token	*scanner_add_token_lit(t_scanner *s, t_token_type type, char *text)
{
	t_list	*lst;

	lst = token_new_list(type, text);
	if (!lst)
		return (NULL);
	ft_lstadd_back(&s->tokens, lst);
	return (lst->content);
}
