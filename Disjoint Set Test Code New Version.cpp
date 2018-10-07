#include<stdio.h>
#include<iostream>

 int sets[10],sizes[10];


 void makesetall()
 {
     int i;
     for(i=0;i<10;i++)
     {
         sets[i]=i;
         sizes[i]=1;
     }
 }

 void unionset(int u,int v)
 {
     int s1=findset(u);
     int s2=findset(v);
     if(s1!=s2)
     {
         if(sizes[s1]<sizes[s2])
         {
             sets[s1]=s2;
             sizes[s2]+=sizes[s1];
         }
         else
         {
             sets[s2]=s1;
             sizes[s1]+=sizes[s2];
         }
     }
 }

 void findset(int V)
 {
     if(sets[V]!=V)
     {
         sets[V]=findset[sets[V];
     }
     //return sets[V];
 }
int main()
 {
     makesetall();
     unionset();
     findset();

 }
