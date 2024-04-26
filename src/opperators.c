/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:34:11 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/26 14:42:44 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_base.h"

void	**del_node(d_list **data, int i)
{
	d_list	*temp;
	d_list	*prev;
	int		count;

	temp = *data;
	prev = NULL;
	count = 1;
	if (!*data || i < 1)
		return (make_res(NULL, (void *)0));
	if (i == 1)
	{
		*data = temp->next;
		return (free(temp), make_res(NULL, (void *)0));
	}
	while (temp != NULL && count < i)
	{
		prev = temp;
		temp = temp->next;
		count++;
	}
	if (temp == NULL)
		return (make_res(NULL, (void *)0));
	prev->next = temp->next;
	return (free(temp), make_res(NULL, (void *)1));
}

void	**edit_node(d_list **data, int i, char *name, void *var)
{
	d_list	*temp;

	if (i == 0)
	{
		if (!new_node(data, name, var))
			return (make_res(NULL, (void *)0));
		return (make_res((*data)->content, (void *)1));
	}
	temp = *data;
	while (i-- > 1 && temp && temp->next)
		temp = temp->next;
	if (i > 0)
		return (make_res(NULL, (void *)0));
	temp->content = var;
	return (make_res(temp->content, (void *)1));
}

void	**read_node(d_list *data, int i)
{
	d_list	*temp;

	if (i == 0)
		return (make_res(NULL, (void *)0));
	temp = data;
	while (i-- > 1 && temp && temp->next)
		temp = temp->next;
	if (i > 0)
		return (make_res(NULL, (void *)0));
	return (make_res(temp->content, (void *)1));
}
