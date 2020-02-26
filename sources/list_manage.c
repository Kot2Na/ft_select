#include "select.h"

int		num_item(t_dlist *start, t_dlist *find)
{
	int i;

	if (find == NULL)
		return (-1);
	if (start)
	{
		i = 0;
		while (start && start != find)
		{
			start = start->next;
			i++;
		}
		if (start == NULL)
			i = -1;
	}
	return (i);
}

t_dlist	*get_item(t_dlist *list, int n)
{
	int i;

	i = 0;
	while (list && i != n)
	{
		list = list->next;
		i++;
	}
	return (list);
}

t_dlist	*remove_item(t_dlist *item)
{
	t_dlist *next;
	t_dlist	*prev;

	next = NULL;
	prev = NULL;
	if (item)
	{
		if (item->next)
			next = item->next;
		if (item->prev)
			prev = item->prev;
		free(item);
		if (next)
			next->prev = prev;
		if (prev)
			prev->next = next;
		if (next == NULL && prev)
		{
			while (prev->prev)
				prev = prev->prev;
			next = prev;
		}
	}
	return (next);
}