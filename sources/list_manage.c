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