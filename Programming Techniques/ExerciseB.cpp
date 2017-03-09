/*
*  Author : Konstantinos Keramaris
*  Products of Store , types 1 2 and 3
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class product
{
    char code[10];
    int n,price,paragontas;
    float price_weight,apothema;
public:
    product(char a[10],int i,float j);
    product(char a[10],int i,float j,int k);
    product(char a[10],float x,float y);
    char* id_code();
    void sale(int k,float i);
    ~product();
};

product::product(char a[10],int i,float j)
{
    strcpy(code,a);
    n=i;
    price=j;
}

product::product(char a[10],int i,float j,int k)
{
    strcpy(code,a);
    n=i;
    price=j;
    paragontas=k;
}

product::product(char a[10],float x,float y)
{
    strcpy(code,a);
    price_weight=x;
    apothema=y;
}

char* product::id_code ()
{
    return code;
}

void product::sale(int l,float i)
{
    float x;
    if (l==1)
    {
        x=i*price;
        cout <<"Timi: \n"<<x;
        n=n-i;
    }else if (l==2)
    {
        if (paragontas>i)
        {
            x=i*price;
        }else
        {
            x=(i-1)*price;
        }
        cout <<"Timi: \n"<<x;
        n=n-i;
    }else if (l==3)
    {
        x=i*price_weight;
        cout <<"Timi: \n"<<x;
        apothema=apothema-i;
    }
}

product::~product()
{
    cout <<"i product katastrafike \n";
}

int main()
{
    char a[10];
    int number,category,i,k,f;
    float j,x,y;
    cout <<"Dwse arithmo proiontwn: \n";
    cin >>number;
    product *p;
    p=(product *)malloc(number*sizeof(product));

    for (f=1;f<=number;i++)
    {
        cout <<"Dwse katigoria proiontos: \n";
        cin >>category;
        if (category==1)
        {
            cout <<"Dwse kwdiko: \n";
            cin >>a;
            cout <<"Dwse arithmo temaxiwn pou iparxoun stin apothiki: \n";
            cin >>i;
            cout <<"Dwse timi gia kathe temaxio: \n";
            cin >>j;
            product temp(a,i,j);
            p[f]=temp;
        }else if (category==2)
        {
            cout <<"Dwse kwdiko: \n";
            cin >>a;
            cout <<"Dwse arithmo temaxiwn pou iparxoun stin apothiki: \n";
            cin >>i;
            cout <<"Dwse timi gia kathe temaxio: \n";
            cin >>j;
            cout <<"Dwse paragonta prosforas: \n";
            cin >>k;
            product temp(a,i,j,k);
            p[f]=temp;
        }else
        {
            cout <<"Dwse kwdiko: \n";
            cin >>a;
            cout <<"Dwse apothema: \n";
            cin >>x;
            cout <<"Dwse timi kilou: \n";
            cin >>y;
            product temp(a,x,y);
            p[f]=temp;
        }

    }

    do
    {
        cout <<"Dwse katigoria proiontwn: \n";
        cin >>number;
        cout <<"Dwse kwdiko proiontos: \n";
        cin >>a;
        cout <<"Dwse arithmo i varos proiontos: \n";
        cin >>x;
        char *b;
        for (i=1;i<=number;i++)
        {
            strcpy(b,p[i].id_code());
            if (strcmp(a,b)!=0)
            {
                break;
            }
        }
        p[i].sale(number,x);
    }while (number !=0);
return 0;
}









