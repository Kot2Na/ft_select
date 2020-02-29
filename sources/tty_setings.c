#include "select.h"

t_ttyinfo *safe_set(t_ttyinfo **item)
{
	static t_ttyinfo *safe;

	if (item = NULL)
		return (safe);
	safe = *item;
	return (*item);
}

t_ttyinfo *init_struct(int ac)
{
	t_ttyinfo *result;

	result = NULL;
	if (!(result = (t_ttyinfo *)malloc(sizeof(t_ttyinfo))))
		print_error("Not enough memory\n", 1);
	if (tgetent(NULL, getenv("TERM")) == 1)
	{
		free(result);
		print_error("Term didn't find\n", 1);
	}
	if ((result->fd = open(ttyname(0), O_RDWR)) < 0)
	{
		free(result);
		print_error("Term didn't open\n", 1);
	}
	result->key = 0;
	result->num = ac - 1;
	tcgetattr(result->fd, &result->term);
	result->term.c_lflag &= ~(ECHO | ICANON);
	result->term.c_oflag &= ~(OPOST);
	result->term.c_cc[VMIN] = 1;
	result->term.c_cc[VTIME] = 0;
	tcsetattr(result->fd, TCSANOW, &result->term);
	return (result);
}