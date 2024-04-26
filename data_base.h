/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_base.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:33:23 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/26 13:08:22 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BASE_H
# define DATA_BASE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	char			*name;
	void			*content;
	struct s_list	*next;
}	d_list;

enum {
    READ,
    EDIT,
    DEL,
    FREE,
    MEM
};

void	**data(int mode, char *name, ...);

void	**edit_node(d_list **data, int i, char *name, void *var);
void	**read_node(d_list *data, int i);
void	**del_node(d_list **data, int i);

void	**make_res(void *cont1, void *cont2);
int		new_node(d_list	**data, void *name, void *var);
int		find_by_name(d_list *data, char *name);

#endif //DATA_BASE_H