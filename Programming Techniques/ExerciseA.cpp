/*
*  Author : Konstantinos Keramaris
*  Social Media User
*/
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

class user
{
    int id_num;
    char name[10],login_name[10],password[10];
    int *friends;
    int a=0;
public:
    void sign_in(int i,char x[10],char y[10]);
    int search_user (char x[10]);
    int identify (char x[10],char y[10]);
    void add (int i);
    int delete_friend (int i);
    int id (int b,int *p);
    void out();
};

void user::sign_in(int n,char x[10],char y[10])
{
    strcpy(login_name,x);
    strcpy(password,y);
    cout <<"Dwse onoma: \n";
    cin >>name;
    id_num=n;
}

int user::search_user(char x[10])
{
    if (strcmp(x,name))
    {
        return 1;
    }
    return 0;
}

int user::identify (char x[10],char y[10])
{
    if (strcmp(x,login_name)&&(strcmp(y,password)))
        return 1;
    return 0;
}

void user::add(int i)
{
    a++;
    friends=(int *)realloc(friends,a*sizeof(int));
    friends[a]=i;
}

int user::delete_friend (int i)
{
    int k;
    for (k=1;k<a+1;k++)
    {
        if (i==friends[k])
        {
            friends[k]=friends[a];
            a--;
            friends=(int *)realloc(friends,a*sizeof(int));
            return 1;
        }
    }
    return 0;
}

int user::id (int b,int *p)
{
    if (b=id_num)
    {
        p=(int *)malloc(a*sizeof(int));
        *p=*friends;
        return a;
    }
}

void user::out ()
{
    cout <<name[10];
}

int main()
{
    char us[10],pass[10],x[10],y[10];
    int n,i,flag;
    n=0;

    cout <<"Dwse username kai password diaxeiristi: \n";
    cin >>us;
    cin >>pass;

    user *users;
    users=(user *)malloc(0*sizeof(user));
    cout <<"Dwse login name: \n";
    cin >>x;
    cout <<"Dwse password: \n";
    cin >>y;
    while ((strcmp(x,us) && strcmp(y,pass)))
    {
        n++;
        users=(user *)realloc(users,n*sizeof(user));
        user users[n];
        users[n].sign_in(n,x,y);
        cout <<"Dwse login name: \n";
        cin >>x;
        cout <<"Dwse password: \n";
        cin >>y;
    }
    cout <<"Eggrafi oloklirwthike \n";

    cout <<"Dwse login name: \n";
    cin >>x;
    cout <<"Dwse password: \n";
    cin >>y;
    while ((strcmp(x,us) && strcmp(y,pass)))
    {
        int b;
        flag=0;
        for (b=1;b<n+1;b++)
        {
            flag=users[b].identify(x,y);
            if (flag=1)
            {
                break;
            }
        }
        int k;
        do
        {
            cout <<"Dwse 1 gia anazitisi kapoiou melous \n";
            cout <<"Dwse 2 gia kataxwrisi filou \n";
            cout <<"Dwse 3 gia diagrafi filou \n";
            cout <<"Dwse 4 gia proboli tis listas filwn \n";
            cout <<"Dwse 0 gia eksodo apo to menou \n";
            cin >>k;
            if (k=1)
            {
                char search_name[10];
                cout <<"Dwse onoma melous: \n";
                cin >> search_name;
                flag=0;
                for (i=1;i<n+1;i++)
                {
                    flag=users[i].search_user(search_name);
                    if (flag=1)
                        break;
                }
                if (flag=0)
                {
                    cout <<"Den iparxei o xristis \n";
                }else
                {
                    cout <<"I tautotita id tou xristi einai:"<<i<<"\n";
                }
            }else if (k=2)
            {
                char search_name[10];
                cout <<"Dwse onoma melous: \n";
                cin >> search_name;
                int flag=0;
                for (i=1;i<n+1;i++)
                {
                    flag=users[i].search_user(search_name);
                    if (flag=1)
                        break;
                }
                if (flag=0)
                {
                    cout <<"Den iparxei o xristis \n";
                }else
                {
                    users[b].add(i);
                    cout <<"O filos prostethike me epitixia \n";
                }
            }else if (k=3)
            {
                char search_name[10];
                cout <<"Dwse onoma filou: \n";
                cin >> search_name;
                int flag=0;
                for (i=1;i<n+1;i++)
                {
                    flag=users[i].search_user(search_name);
                    if (flag=1)
                        break;
                }
                if (flag=0)
                {
                    cout <<"Den iparxei o xristis \n";
                }else
                {
                    int flag_2=0;
                    users[b].delete_friend(i);
                    if (flag_2=0)
                    {
                        cout <<"O xristis den iparxei stin lista filwn \n";
                    }else
                    {
                        cout <<"O xristis diagrafike epitixws \n";
                    }
                }
            }else if(k=4)
            {
                int c=0,d;
                int *p;
                c=users[b].id(b,p);
                if (c=0)
                {
                    cout <<"Den exeis kataxwrimenous filous \n";
                }else
                {
                    for (d=1;d<c+1;d++)
                    {
                        int e;
                        e=p[d];
                        users[e].out();
                    }
                }
            }
        }while (k !=0 );

        cout <<"Dwse login name: \n";
        cin >>x;
        cout <<"Dwse password: \n";
        cin >>y;
    }
    return 0;
}
