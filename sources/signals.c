# include "select.h"

void    size_changed(int s)
{
    t_ttyinfo   *tty;
    t_dlist     *head;

    (void)s;
    tty = NULL;
    tty = safe_tty(&tty);
    head = gohead_list(tty->cursor);
	if (tgetent(NULL, getenv("TERM")) <= 0)
    {
		ft_putstr_fd("Term didn't find\n", 2);
        main_end(1, head, tty);
    }
    print_items(head, tty);
}

void    set_signals(t_ttyinfo *tty)
{
    safe_tty(&tty);
    signal(SIGWINCH, size_changed);
}