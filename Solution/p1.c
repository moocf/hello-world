/*
Problem - 1
written in C

Subhajit Sahu
Team ID:HW1162
*/

#include<stdio.h>
#include<stdlib.h>

int main(void);
long trip(void);


long *g;
long glenmax, glen, ptr;
long t, r, k, n, s;




int main(void)
	{
	long i, j;
	glenmax = 256;
	g = (long*)malloc(glenmax * sizeof(long));
	
	scanf("%d", &t);
	for(i=0; i<t; i++)
		{
		scanf("%d %d %d", &r, &k, &n);
		glen = n;
		if(glen > glenmax)
			{
			glenmax = glen;
			free(g);
			g = (long*)malloc(glenmax * sizeof(long));
			}
		for(j=0; j<n; j++)
			scanf("%d", g+j);
		
		s = 0;
		ptr = 0;
		for(j=0; j<r; j++)
			{
			s += trip();
			}
		printf("%d\n", s);
		}
	free(g);
	return(0);
	}





long trip(void)
	{
	long p, ptrstart;
	p = 0;
	ptrstart = ptr;
	do
		{
		p += g[ptr];
		ptr++;
		if(ptr >= glen) ptr = 0;
		}
	while((p <= k) && (ptr != ptrstart));
	if(p > k)
		{
		ptr--;
		if(ptr < 0) ptr = glen - 1;
		p -= g[ptr];
		}
	return(p);
	}

