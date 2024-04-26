/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:49:02 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/26 14:42:46 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_base.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && i < n)
	{
		if (!s1[i++])
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	find_by_name(d_list *data, char *name)
{
	int		i;
	d_list	*node;

	i = 1;
	node = data;
	while (node)
	{
		if (!ft_strncmp(node->name, name, 128))
			return (i);
		node = node->next;
		i ++;
	}
	return (0);
}

static void	ft_lstadd_back(d_list **lst, d_list *new)
{
	if (*lst)
		ft_lstadd_back(&(*lst)->next, new);
	else
		*lst = new;
}

int	new_node(d_list	**data, void *name, void *var)
{
	d_list	*node;

	node = (d_list *)malloc(sizeof(d_list));
	if (!node)
		return (0);
	node->name = name;
	node->content = var;
	ft_lstadd_back(data, node);
	return (1);
}

void	**make_res(void *cont1, void *cont2)
{
	void	**res;
	void	**temp;

	temp = (void **)malloc(2 * sizeof(void *));
	if (!temp)
		return (NULL);
	temp[0] = cont1;
	temp[1] = cont2;
	res = temp;
	free(temp);
	return (res);
}


