/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:07:37 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 18:30:56 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	right_key(t_dlist *list, t_ttyinfo *tty)
{
	int	x;
	int	y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x + 1, y);
	}
}

void	left_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x - 1, y);
	}
}

void	up_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x, y + 1);
	}
}

void	down_key(t_dlist *list, t_ttyinfo *tty)
{
	int x;
	int y;

	if (list && tty)
	{
		get_cor(list, tty, &x, &y);
		change_cursor(list, tty, x, y - 1);
	}
}
