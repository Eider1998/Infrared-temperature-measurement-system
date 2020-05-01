在这里插入代码片#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 typedef struct st
{
    int l,r;
    char data;
}tree;
//若把tree1[20],tree2[20]放在结构体后面出错，因为前面为typedef .
tree tree1[20],tree2[20];
int n,m;
void create(tree*t,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        char s;
        cin>>s;
        t[i].data=s;
        cin>>s;
        if(s == '-')
            t[i].l=15;
        else
            t[i].l=s-'0';
        cin>>s;
        if(s == '-')
            t[i].r=15;
        else
            t[i].r=s-'0';
    }
}
int kan(int i,int j)
{
   if(tree1[tree1[i].l].data == tree2[tree2[j].l].data&&tree1[tree1[i].r].data == tree2[tree2[j].r].data)
    return 1;
    if(tree1[tree1[i].l].data == tree2[tree2[j].r].data&&tree1[tree1[i].r].data == tree2[tree2[j].l].data)
        return 1;
    return 0;

}
void panduan()
{
    int i,j;
    int f=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //判断tree1的结点在tree2中对应的结点的左右孩子值是否一样或相反。
            if(tree1[i].data == tree2[j].data)
            {
                if(kan(i,j) == 0)
                {
                    f=1;
                    break;
                }
                else
                    break;
            }
        }
        if(j == m)
        {
            f=1;
            break;
        }
    }
    if(f == 1)
        printf("No\n");
    else
        printf("Yes\n");
}
int main()
{
  while(scanf("%d",&n)!=EOF)
  {
  create(tree1,n);
  cin>>m;
  create(tree2,m);
  panduan();
  }
    return 0;
}

