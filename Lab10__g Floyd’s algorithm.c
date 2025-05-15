
#include &lt;stdio.h&gt;
int a[10][10],D[10][10],n;
void floyd(int [][10],int);
int min(int,int);
int main()
{
printf(&quot;Enter the no. of vertices:&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the cost adjacency matrix:\n&quot;);
int i,j;
for(i=0;i&lt;n;i++){
for(j=0;j&lt;n;j++){
scanf(&quot;%d&quot;,&amp;a[i][j]);
}
}
floyd(a,n);
printf(&quot;Distance Matrix:\n&quot;);
for(i=0;i&lt;n;i++){
for(j=0;j&lt;n;j++){
printf(&quot;%d &quot;,D[i][j]);
}
printf(&quot;\n&quot;);
}
return 0;
}

void floyd(int a[][10],int n){
int i,j,k;
for(i=0;i&lt;n;i++){
for(j=0;j&lt;n;j++){
D[i][j]=a[i][j];
}
}

for(k=0;k&lt;n;k++){
for(i=0;i&lt;n;i++){
for(j=0;j&lt;n;j++){
D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
}
}
}
}

int min(int a,int b){
if(a&lt;b){
return a;
}else{
return b;
}
}

OUTPUT:
Enter the no. of vertices:4

Enter the cost adjacency matrix:
0 99 3 99
2 0 99 99
99 6 0 1
7 99 99 0
Distance Matrix:
0 9 3 4
2 0 5 6
8 6 0 1
7 16 10 0
