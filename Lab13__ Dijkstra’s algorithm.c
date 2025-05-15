#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
void main()
{
int i,j,n,v,k,min,u,c[20][20],s[20],d[20];
clrscr();
printf(&quot;\n Enter the no. of vertices : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\n Enter the cost adjacency matrix : &quot;);
printf(&quot;\n Enter 999 for no edge &quot;);
for(i=1;i&lt;=n;i++)
{
for(j=1;j&lt;=n;j++)
{
scanf(&quot;%d&quot;,&amp;c[i][j]);
}
}
printf(&quot;\n Enter the source vertex : &quot;);
scanf(&quot;%d&quot;,&amp;v);
for(i=1;i&lt;=n;i++)
{
s[i]=0;
d[i]=c[v][i];
}
d[v]=0;
s[v]=1;
for(k=2;k&lt;=n;k++)
{
min=999;
for(i=1;i&lt;=n;i++)
{
if((s[i]==0)&amp;&amp;(d[i]&lt;min))
{
min=d[i];
u=i;
}
}
s[u]=1;
for(i=1;i&lt;=n;i++)
{

if(s[i]==0)
{
if(d[i]&gt;(d[u]+c[u][i]))
{
d[i]=d[u]+c[u][i];
}
}

}
}
printf(&quot;\n The shortest distance from %d is &quot;,v);
for(i=1;i&lt;=n;i++)
{
printf(&quot;\n %d --&gt; %d = %d &quot;,v,i,d[i]);
}
getch();
}


OUTPUT

Enter the no. of vertices: 5
Enter the cost adjacency matrix:
Enter 999 for no edge:
999 7 3 999 999
7 999 2 5 4
3 2 999 4 999
999 5 4 999 6
999 4 999 6 999
Enter the source vertex: 1
The shortest distance from 1 is:
1 --&gt; 1 = 0
1 --&gt; 2 = 5
1 --&gt; 3 = 3
1 --&gt; 4 = 7
1 --&gt; 5 = 9
