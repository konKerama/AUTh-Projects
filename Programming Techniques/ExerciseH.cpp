/*
*  Author : Konstantinos Keramaris
*  P : daily max power
*  FR : daily fuel consumption on max power
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class oil_burner
{
    char id[10];
    int max_p,daily_cons,cost_mon,cost_buy,cost_sint;
public:
    oil_burner();
    float getp_fr();
    int getp(){return max_p;}
    int getm(){return cost_buy;}
    float cost_year();
    char* getid(){return id;}
};

oil_burner::oil_burner()
{
    cout<<"Dwse stoixeia kaustira petrelaiou";
    cin>>id;
    cin>>max_p;
    cin>>daily_cons;
    cin>>cost_mon;
    cin>>cost_buy;
    cin>>cost_sint;
}

float oil_burner::getp_fr()
{
    float p;
    p=max_p/daily_cons;
    return p;
}

float oil_burner::cost_year()
{
    float a;
    a=daily_cons*cost_mon+cost_sint;
    return a;
}
//------------------------------------------------------------------------------------------
class gas_burner
{
    char id[10];
    int max_p,daily_cons,cost_mon,cost_buy,cost_sint,cost_sind;
public:
    gas_burner();
    float getp_fr();
    int getp(){return max_p;}
    int getm(){return (cost_buy+cost_sind);}
    float cost_year();
    char* getid() {return id;}
};

gas_burner::gas_burner()
{
    cout<<"Dwse stoixeia kaustira aeriou";
    cin>>id;
    cin>>max_p;
    cin>>daily_cons;
    cin>>cost_mon;
    cin>>cost_buy;
    cin>>cost_sint;
    cin>>cost_sind;
}

float gas_burner::getp_fr()
{
    float p;
    p=max_p/daily_cons;
    return p;
}

float gas_burner::cost_year()
{
    float a;
    a=daily_cons*cost_mon+cost_sint;
    return a;
}
//-------------------------------------------------------------------------------
template <class burner> class device
{
    int n;
    burner *a=new burner;
public:
    device();
    burner* b_short();
};

template <class burner>
device<burner>::device()
{
    cout<<"Dwse megethos pinaka: \n";
    cin>> n;
    a=(burner *)malloc(n*sizeof(burner));
}

template <class burner> burner* device<burner>::b_short()
{
    int i,j;
    int p1,p2;
    burner temp;
    for (i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            p1=a[j].getp_fr();
            p2=a[j+1].getp_fr();
            if (p2>p1)
            {
                temp=a[j];
                a[i]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return a;
}
//-----------------------------------------------------------------
template <oil_burner* burner1,gas_burner* burner2>
void choice(burner1 &b1,burner2 &g,int min_p,int money,int days)
{
    int n1,n2;
    int i;
    int p,m;
    int flag1,flag2;
    n1=sizeof(b1);
    n2=sizeof(g);
    for (i=0;i<n1;i++)
    {
        p=b1[i].getp();
        m=b1[i].getmoney();
        if ((p>=min_p)&&(m<=money))
            flag1=i
    }
    for (i=0;i<n2;i++)
    {
        p=g[i].getp();
        m=g[i].getmoney();
        if ((p>=min_p)&&(m<=money))
            flag2=i
    }
    float cost_y1,cost_y2;
    int costb1,costb2;
    cost_y1=b1[flag1].cost_year();
    cost_y2=g[flag2].cost_year();
    costb1=b1[flag1].getmoney();
    costb2=g[flag2].getmoney();
    int temp=0;
    char id[10];
    float time;
    if (cost_y1>cost_y2)
    {
        if(costb1>costb2)
        {
            id=g[flag2].getid();
            cout<<id;
        }else
        {
            id=b1[flag1].getid();
            time=(costb1-costb2)/(cost_y1-cost_y2);
            cout>>id;
            cout>>time;
        }
    }else
    {
         if(costb1<costb2)
        {
            id=b1[flag1]getid();
            cout<<id;
        }else
        {
            id=g[flag2].getid();
            time=(costb2-costb10)/(cost_y2-cost_y1);
            cout>>id;
            cout>>time;
        }
    }
}    return *a;


int main()
{
    int min_p,money,days;
    cout<<"Dwse elaxisti isxu, diathesima xrimata kai imeres leitourgeias thermansis";
    cin>>min_p;
    cin>>money;
    cin>>days;
    device<oil_burner> a;
    device<gas_burner> b;
    oil_burner *o;
    gas_burner *g;
    o=a.b_short();
    g=b.b_short();
    choice(o,g,min_p,money,days);
    return 0;
}
