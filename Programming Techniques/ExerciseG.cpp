#include <iostream>
#include <stdlib.h>

using namespace std;

class neurons
{
    int state,*tautotites,*vari,katwfli,a;
public:
    neuron(){}
    friend istream &operator>(istream &s,neuron &a);
    void *operator new[](size_t n);
    int getkat(){return katwfli;}
    int sum();
    int setstate(int a){state=a;}
    int getstate(){return state;}
};

istream &operator>(istream &s,neuron &a)
{
    cin >>a;
    cout<<"Dwse tautotites kai vari neurwnwn \n"
    int i;
    tautotites=(int *)malloc((a)*sizeof(int));
    vari=(int *)malloc((a)*sizeof(int));

    for (i=1;i<a;i++)
    {
        cin >>tautotites[i];
        cin >>vari[i];
    }
    cout <<"dwse katwfli kai arxiki katastati";
    cin >>katwfli;
    cin >>state;
}

neuron *operator new[] (size_t n);
{
    void *p;
    p=malloc(n);
    return p;
}

int neuron::sum ()
{
    int i,summ=0;
    for (i=0;i<a;i++)
    {
        summ=vari[i]*tautotites[i];
    }
    return summ;
}

class network
{
    int n;
    char final_state[10];
    neuron *neurons;
public:
    network ();
    void *operator new[]();
    friend ostream &operator <(ostream &s,network &a);
    void calk_state();
};

network::network()
{
    cou <<"Dwse arithmo neurwnwn"'
    cin >>n;
}

network *operator new[]()
{
    int i,j;
    cout<<"Dwse arithmo neurwnwn \n";
    cin>>i;
    void p(i);
    neurons = new neuron[n];
    for (j=0;j<n;j++)
    {
        cin > neurons[i];
    }
    return p;
}

ostream &operator <(ostream &s,network &a)
{
    cout <<final_state[10];
    int s,i;
    for (i=0;i<n;i++)
    {
        s=neurons[i].getstate();
        cout <<s;
    }

}

void network::calk_state()
{
    int n_max;
    cout <<"megistos arithmos epanalipsewn";
    cin >>n_max;
    final_state="unstable";
    int i=0,j=0;
    int kat,sum,s;
    int test[n];
    while ((!strcmp(final_state,"stable"))&&(j<=n_max))
    {
        for (i=0;i<n;i++)
        {
            kat=neurons[i].getkat();
            sum=neurons[i].sum();
            s=neurons[i].getstate();
            if (sum>kat)
            {
                if (s==1)
                {
                    test[i]=1;
                }
                neurons[i].setstate(1);
            }else
            {
                if (s==-1)
                {
                    test[i]=1;
                }
                neurons[i].setstate(-1);
            }
        }
        flag=0;
        for (i=0;i<n;i++)
        {
            if (test[i]==0)
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            final_state="stable";
        }

        j++
    }
}

int main ()
{
    net = new network();
    net.calk_state();
    cout < net;
}
