/*
Problem - 2
written in C++

Subhajit Sahu
Team ID:HW1162
*/

#include<iostream>
#include<cstdlib>


using namespace std;

int main(void);
long possible(void);


char **g;
char *rmax, *cmax;
long grmax, gcmax, gr, gc;
long t;




int main(void)
	{
	long i, j, k;
	grmax = 10;
	gcmax = 10;
	g = new char*[grmax];
	for(i=0; i<grmax; i++)
		g[i] = new char[gcmax];
	rmax = new char[grmax];
	cmax = new char[gcmax];
	
	cin>>t;
	for(i=0; i<t; i++)
		{
		cin>>gr>>gc;
		if((gr > grmax) || (gc > gcmax))
			{
			grmax = gr;
			gcmax = gc;
			delete g;
			g = new char*[grmax];
			for(k=0; k<grmax; k++)
				g[k] = new char[gcmax];
			delete rmax;
			rmax = new char[grmax];
			delete cmax;
			cmax = new char[gcmax];
			}
		for(j=0; j<gr; j++)
			{
			for(k=0; k<gc; k++)
				cin>>g[j][k];
			rmax[j] = 'a';
			cmax[j] = 'a';
			}
		cout<<possible()<<endl;
		}
	delete g;
	return(0);
	}





long possible(void)
	{
	char z;
	long i, j, ways = 1;
	
	for(i=0; i<gr; i++)
		{
		for(j=0; j<gc; j++)
			{
			if(g[i][j] == '.')
				{
				z = rmax[i];
				if(cmax[j] > z) z = cmax[j];
				g[i][j] = z; //no need
				ways *= ('z' - z + 1);
				}
			else
				{
				if(g[i][j] >= rmax[i]) rmax[i] = g[i][j];
				else return(0);
				if(g[i][j] >= cmax[j]) cmax[j] = g[i][j];
				else return(0);
				}
			}
		}
	return(ways % 10007);
	}

