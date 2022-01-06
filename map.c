#include "fillit.h"

void printtomap(int i, t_tetris *alltetri, unsigned short *map)
{
	unsigned short mask;
	int k;

 	mask = 61440;
	k = -1;
	while(++k < alltetri[i].size->y)
	{
		map[alltetri[i].pos->y + k] |= ((alltetri[i].shape & mask) >> alltetri[i].pos->x << (4*k));
		mask = mask >> 4;
	}

}

void remofmap(int i, t_tetris *alltetri, unsigned short *map)
{
	unsigned short mask;
	int k;

	mask = 61440;
	k = -1;

	while(++k < alltetri[i].size->y)
	{
		map[alltetri[i].pos->y + k] ^= ((alltetri[i].shape & mask) >> alltetri[i].pos->x << (4*k));
		mask = mask >> 4;
	}
}

int	collisioncheck(int i, t_tetris *alltetri, unsigned short *map)
{
	unsigned short mask;
	int k;

	k = -1;
	mask = 61440;
	while(++k < alltetri[i].size->y)
	{
		if(map[alltetri[i].pos->y + k]
		& ((alltetri[i].shape & mask) >> alltetri[i].pos->x << (4*k)))
			return (0);
		mask = mask >> 4;
	}
	return (1);
}