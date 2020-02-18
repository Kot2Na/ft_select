#include "select.h"

t_dlist	*newitem_list(char *item)
{
	t_dlist	*new;

	new = NULL;
	if (item)
	{
		new = (t_dlist*)malloc(sizeof(t_dlist));
		new->item = item;
		new->selected = 0;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void	toend_list(t_dlist **head, t_dlist *new)
{
	t_dlist *iter;

	if (head)
	{
		if (*head)
		{
			iter = *head;
			while (iter->next)
				iter = iter->next;
			new->prev = iter;
			iter->next = new;
		}
		else
			*head = new;
	}
}

t_dlist *create_list(char **av)
{
	int		i;
	t_dlist	*result;

	result = NULL;
	i = 1;
	if (av)
	{
		while (av[i])
		{
			toend_list(&result, newitem_list(av[i]));
			i++;
		}
	}
	return (result);
}

t_dlist	*gohead_list(t_dlist *list)
{
	if (list)
		while (list->prev)
			list = list->prev;
	return (list);
}

void	destr_list(t_dlist *list)
{
	if (list)
	{
		destr_list(list->next);
		free(list);
	}
}