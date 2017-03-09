/*
*  Author : Konstantinos Keramaris
*  Operators
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class vector;
//-----------------------matrix-------------------------
class matrix
{
	float **p1;
	int n;
public:
	matrix(int x);
	matrix(int x,int y);
	void getp1(float **a);
	int getn(void);
	void setp1(float **a);
	float* operator[](int x);
	vector operator!(void);
	vector operator~(void);
};

class vector
{
	float *p2;
	int n;
public:
	vector(int x);
	vector(int x, int y);
	void setp2(float *a);
	void getp2(float *a);
	void out();
	int operator>(vector a);
	vector operator=(matrix a);
	vector operator-(vector a);
	float operator++();
};

matrix::matrix(int x)
{
	int i, j;
	n = x;
	p1 = (float **)malloc(n*sizeof(float *));
	for (i = 0; i < n; i++)
	{
		p1[i] = (float *)malloc(n*sizeof(float));
	}
	cout << "Dwse stoixeia tetragwnikou pinaka: /n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Stoixeio(" << i << "," << j << ")";
			cin >> p1[i][j];
		}
	}
}

matrix::matrix(int x,int y)
{
    int i, j;
	n = x;
	p1 = (float **)malloc(n*sizeof(float *));
	for (i = 0; i < n; i++)
	{
		p1[i] = (float *)malloc(n*sizeof(float));
	}
}

void matrix::getp1(float **a)
{
	a = p1;
}

int matrix::getn(void)
{
	return n;
}

void matrix::setp1(float **a)
{
    p1=a;
}

float* matrix::operator[](int x)
{
	return p1[x];
}

vector matrix::operator!(void)
{
	int i = 0;
	int j = 0;;
	vector t(n,i);
	float *k;
	k = (float *)malloc(n*sizeof(float));
	for (i = 0; i < n; i++)
	{
		k[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (p1[i][j] > 0)
				{
					k[i] = k[i] + p1[i][j];
				}
				else
				{
					k[i] = k[i] - p1[i][j];
				}
			}
		}
	}
	t.setp2(k);
	return t;
}

vector matrix::operator~(void)
{
	int i = 0;
	int j = 0;
	vector t(n, i);
	float *k;
	k = (float *)malloc(n*sizeof(float));
	for (i = 0; i < n; i++)
	{
		k[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (p1[i][j] > 0)
				{
					k[i] = k[i] + p1[j][i];
				}
				else
				{
					k[i] = k[i] - p1[i][j];
				}
			}
		}
	}
	t.setp2(k);
	return t;
}


//-----------------------vector-------------------------


vector::vector(int x)
{
	int i;
	n = x;
	p2 = (float *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		cout << "Dwse to stoixeio" << i << "tou monodiastatou pinaka";
		cin >> p2[i];
	}
}

vector::vector(int x, int y)
{
	n = x;
	p2 = (float *)malloc(n*sizeof(float));
}

void vector::setp2(float *a)
{
	p2 = a;
}

void vector::getp2(float *a)
{
	a = p2;
}

void vector::out()
{
    int i;
    for (i=0;i<n;i++)
    {
        cout <<p2[i];
    }
}

int vector::operator>(vector a)
{
	int x = 1;
	int i;
	float *k;
	k = (float *)malloc(n*sizeof(float));
	for ( i = 0; i < n; i++)
	{
		k[i] = 0;
	}
	vector::getp2(k);
	for (i = 0; i < n; i++)
	{
		if (p2[i] < k[i] )
		{
			x = 0;
			return x;
		}
	}
	return x;
}

vector vector::operator=(matrix a)
{
	int i=0;
	int j=0;
	n = a.getn();
	vector x(n,i);
	float **k,*l;
	l = (float *)malloc(n*sizeof(int));
	a.getp1(k);
	for (i = 0; i < n; i++)
	{
		if (k[i][j]>0)
		{
			l[i] = k[i][j];
		}
		else
		{
			l[i] = -k[i][i];
		}
	}
	x.setp2(l);
	return x;
}

vector vector::operator-(vector a)
{
	int i;
	vector x(n,i);
	float *l;
	for (i = 0; i < n; i++)
	{
		l[i] = l[i] - a.p2[i];
	}
	x.setp2(l);
	return x;
}

float vector::operator++()
{
	float x = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		x = x + p2[i];
	}
	return x;
}

int main()
{
	int m;
	cout << "Dwse arithmo stilwn kai grammwn tetragwnikou pinaka";
	cin >> m;
	matrix a(m);
	int i = 0;
	int j = 0;
	vector v(m,i);
	v=a;
	vector v1(m,i);
	vector v2(m,i);
	v1=!a;
	v2=~a;
	int flag1,flag2;
	flag1=v>v1;
	flag2=v>v2;
	if (flag1!=0 && flag2!=0)
    {
        vector v3(m,i);
        vector v4(m,i);
        v3=v-v1;
        v4=v-v2;
        v3.out();
        v4.out();
        float x,y;
        x=++v3;
        y=++v4;
        cout <<x,y;
    }
	return 0;
}
