#include <stdlib.h>

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void	fill(char **tab, t_point size, t_point pos, char target)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x
			|| pos.y >= size.y)
		return ;
	if (tab[pos.y][pos.x] != target)
		return ;
	tab[pos.y][pos.x] = 'F';
	fill(tab, size, (t_point){pos.x - 1, pos.y}, target);
	fill(tab, size, (t_point){pos.x + 1, pos.y}, target);
	fill(tab, size, (t_point){pos.x, pos.y - 1}, target);
	fill(tab, size, (t_point){pos.x, pos.y + 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];

	if (target == 'F')
		return ;
	fill(tab, size, begin, target);
}
