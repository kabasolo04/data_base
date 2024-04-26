/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:57 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/26 14:42:39 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_base.h"


static void	free_list(d_list **lst)
{
	if (!*lst)
		return ;
	free_list(&(*lst)->next);
	free (*lst);
	*lst = NULL;
}

void	**data(int mode, char *name, ...)
{
	static d_list	*data_base;
	va_list			va;
	void			*var;
	int				i;

	if (mode == FREE)
		return (free_list(&data_base), make_res(NULL, (void *)1));
	if (mode == MEM)
		return (make_res(&data_base, (void *)1));
	va_start(va, name);
	var = va_arg(va, void *);
	va_end(va);
	if (!name)
		return (make_res(NULL, (void *)0));
	i = find_by_name(data_base, name);
	if (mode == DEL)
		return (del_node(&data_base, i));
	if (mode == READ)
		return (read_node(data_base, i));
	if (mode == EDIT)
		return (edit_node(&data_base, i, name, var));
	return (make_res(NULL, (void *)0));
}
