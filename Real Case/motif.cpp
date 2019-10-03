#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
  int i,j;
    int nos[12];
    int nmer=9;
    string str[12];
    string strnew[12];
    int a[9];
    int c[9];
    int g[9];
    int t[9];
int maxi(int q,int w,int e,int r)
{
    if((q>=w)&&(q>=e)&&(q>=r))
        return q;
    else if((w>=q)&&(w>=e)&&(w>=r))
        return w;
    else if((e>=w)&&(e>=q)&&(e>=r))
        return e;
    else
     return r;
}
void con(string a1,int i)
{
    if(i==9)
    {
        cout<<a1<<endl;
    }
    else{
    if(a[i]==maxi(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('A');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    if(c[i]==maxi(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('C');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    if(t[i]==maxi(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('T');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
      if(g[i]==maxi(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('G');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
}
}
int main()
{

for(i=0;i<nmer;i++)
{
    a[i]=c[i]=g[i]=t[i]=0;
}

    cout<<"ENTER THE DNA STRUCTURE"<<endl;
    for(i=0;i<12;i++)
    {
        getline(cin,str[i]);
    }
    cout<<"ENTRE THE SEQUENCE SET";
    for(i=0;i<12;i++)
    {
        cin>>nos[i];
    }
   /* cout<<"ENTER N";
    cin>>nmer;*/
    for(i=0;i<12;i++)
    {
       strnew[i]=str[i].substr(nos[i],nmer);
       cout << strnew[i] << endl;
    }

    for(i=0;i<12;i++)
    {
        for(j=0;j<nmer;j++)
        {

     char ch=strnew[i][j];
     if(ch=='T')
        {
            t[j]++;
     }
     else if(ch=='A')
        {
            a[j]++;
            }
         else if(ch=='G')
        {
            g[j]++;
     }
    else if(ch=='C')
        {
            c[j]++;
        }

    }
}
for(i=0;i<12;i++)
    {
    cout<<strnew[i]<<endl;
    }


for(i=0;i<nmer;i++)
{
cout<<a[i]<<" ";
}
cout<<endl;
for(i=0;i<nmer;i++)
{
cout<<c[i]<<" ";
}
cout<<endl;
for(i=0;i<nmer;i++)
{
cout<<g[i]<<" ";
}
cout<<endl;
for(i=0;i<nmer;i++)
{
cout<<t[i]<<" ";
}
cout<<endl;
con("",0);
}
