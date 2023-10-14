#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int ret;

	ret = ft_printf("yolo %c %c hihi\n", 'c', 0);
	dprintf(2, "%d\n", ret);
	ret = ft_printf("yolo %c %c hihi\n", 'c', 0);
	dprintf(2, "%d\n", ret);

	return (0);
}
