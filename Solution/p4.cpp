/*
Problem - 4
written in C++

Subhajit Sahu
Team ID:HW1162
*/

#include<iostream>
#include<cstdlib>
#include<string.h>


using namespace std;

int main(void);
void find(void);
int simonsi(void);
int philiphi(void);
void remove(int pos);


char str0[51], str[51];
int slen, last;
long t;



int main(void)
	{
	long i;
	
	cin>>t;
	for(i=0; i<t; i++)
		{
		cin>>str0;
		slen = strlen(str0);
		find();
		}
	return(0);
	}

void find(void)
	{
	last = 0;
	strcpy(str, str0);
	while(1)
		{
		if(simonsi()) break;
		if(philiphi()) break;
		}
	if(strcmp(str, str0) > 0) cout<<"Simonsi\n";
	else cout<<"Philiphi\n";
	}

int simonsi(void)
	{
	int i;
	for(i=last; i<slen-1; i++)
		{
		if(str[i+1] > str[i])
			{
			remove(i);
			last = i;
			return(0);
			}
		}
	return(1);
	}

int philiphi(void)
	{
	int i;
	for(i=last; i<slen-1; i++)
		{
		if(str[i+1] < str[i])
			{
			remove(i);
			return(0);
			}
		}
	return(1);
	}

void remove(int pos)
	{
	char *p1, *p2;
	p1 = str + pos;
	p2 = str + pos + 1;
	while(*p2 != '\0')
		{
		*p1 = *p2;
		p1++;
		p2++;
		}
	*p1 = '\0';
	slen--;
	}

