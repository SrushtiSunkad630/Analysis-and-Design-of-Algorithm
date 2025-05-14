#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;time.h&gt;
void heapcom(int a[],int n)
{
int i,j,k,item;
for(i=1;i&lt;=n;i++)
{
item=a[i];
j=i;
k=j/2;
while(k!=0 &amp;&amp; item&gt;a[k])
{
a[j]=a[k];
j=k;
k=j/2;
}
a[j]=item;
}
}
void adjust(int a[],int n)
{
int item,i,j;
j=1;
item=a[j];
i=2*j;
while(i&lt;n)
{
if((i+1)&lt;n)
{
if(a[i]&lt;a[i+1])
i++;
}
if(item&lt;a[i])
{
a[j]=a[i];
j=i;
i=2*j;
}
else
break;
}
a[j]=item;
}
void heapsort(int a[],int n)
{

int i,temp;
delay(1000);
heapcom(a,n);
for(i=n;i&gt;=1;i--)
{
temp=a[1];
a[1]=a[i];
a[i]=temp;
adjust(a,i);
}
}
void main()
{
int i,n,a[20],ch=1;
clock_t start,end;
clrscr();
while(ch)
{
printf(&quot;\n enter the number of elements to sort\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\n enter the elements to sort\n&quot;);
for(i=1;i&lt;=n;i++)
scanf(&quot;%d&quot;,&amp;a[i]);
start=clock();
heapsort(a,n);
end=clock();
printf(&quot;\n the sorted list of elemnts is\n&quot;);
for(i=1;i&lt;=n;i++)
printf(&quot;%d\n&quot;,a[i]);
printf(&quot;\n Time taken is %lf CPU cycles\n&quot;,(end-start)/CLK_TCK);
printf(&quot;do u wish to run again (0/1)\n&quot;);
scanf(&quot;%d&quot;,&amp;ch);
}
getch();
}

OUTPUT
enter the number of elements to sort : 5
enter the elements to sort : 8 5 6 3 1
the sorted list of elements is 1 3 5 6 8
