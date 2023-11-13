#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac < 2)
	{
		dprintf(1, "you didnt put any path you dummie\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(1, "open didnt work\n");
		return (0);
	}
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);
	// line = get_next_line(fd);
	// dprintf(1, "%s", line);

	line = get_next_line(fd);
	dprintf(1, "%s", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		dprintf(1, "%s", line);
	}
	close(fd);
	return (0);
}


/*

Attablé à la terrasse d’un grand Café
Dégustant, savourant ce bon moment de paix
L’homme, naguère tranquille, est absorbé
Malgré le tintamarre, malgré le grand bruit

Sa plume frêle zigzague sur une page
Il y transcrit des songes et de beaux rivages
Des horizons lointains et de belles plages
Rien autour de lui ne le trouble, ni l’ennuie

Sa muse si lancinante le met en transe
Ses doigts dynamisés frétillent en cadence
Ses yeux brillants ne clignent plus, en permanence
Ses vers sont un bijou qui scintille et reluit

Et puis tout d’un coup son corps se rassérène
Son cœur jubile et son âme devient amène
Son visage se déride par cette aubaine
Car lui seul de ce beau poème se réjouit

œ

*/
