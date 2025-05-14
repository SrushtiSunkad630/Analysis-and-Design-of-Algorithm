//C program to implement topological sort using DFS
#include &lt;stdio.h&gt;
int n, a[10][10], res[10], s[10], top = 0;
void dfs(int, int, int[][10]);
void dfs_top(int, int[][10]);
int main()
{
printf(&quot;Enter the no. of nodes&quot;);
scanf(&quot;%d&quot;, &amp;n);
int i, j;
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
scanf(&quot;%d&quot;, &amp;a[i][j]);
}
}
dfs_top(n, a);
printf(&quot;Solution: &quot;);
for (i = n - 1; i &gt;= 0; i--) {
printf(&quot;%d &quot;, res[i]);
}
return 0;
}
void dfs_top(int n, int a[][10]) {
int i;
for (i = 0; i &lt; n; i++) {
s[i] = 0;
}
for (i = 0; i &lt; n; i++) {
if (s[i] == 0) {
dfs(i, n, a);
}
}
}
void dfs(int j, int n, int a[][10]) {
s[j] = 1;
int i;
for (i = 0; i &lt; n; i++) {
if (a[j][i] == 1 &amp;&amp; s[i] == 0) {
dfs(i, n, a);
}
}
res[top++] = j;
}
OUTPUT:

Enter the no. of nodes6
0 0 1 1 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
Solution: 1 4 0 2 3 5

  
//C program to implement topological sort using source removal method
#include&lt;stdio.h&gt;
int a[10][10],n,t[10],indegree[10];
int stack[10],top=-1;
void computeIndegree(int,int [][10]);
void tps_SourceRemoval(int,int [][10]);
int main(){
printf(&quot;Enter the no. of nodes: &quot;);
scanf(&quot;%d&quot;,&amp;n);
int i,j;
for(i=0;i&lt;n;i++){
for(j=0;j&lt;n;j++){
scanf(&quot;%d&quot;,&amp;a[i][j]);
}
}
computeIndegree(n,a);
tps_SourceRemoval(n,a);
printf(&quot;Solution:&quot;);
for(i=0;i&lt;n;i++){
printf(&quot;%d &quot;,t[i]);
}
return 0;
}
void computeIndegree(int n,int a[][10]){
int i,j,sum=0;
for(i=0;i&lt;n;i++){
sum=0;
for(j=0;j&lt;n;j++){
sum=sum+a[j][i];
}
indegree[i]=sum;
}
}
void tps_SourceRemoval(int n,int a[][10]){
int i,j,v;
for(i=0;i&lt;n;i++){
if(indegree[i]==0){
stack[++top]=i;
}
}

int k=0;
while(top!=-1){
v=stack[top--];
t[k++]=v;
for(i=0;i&lt;n;i++){
if(a[v][i]!=0){
indegree[i]=indegree[i]-1;
if(indegree[i]==0){
stack[++top]=i;
}
}
}
}
}
OUTPUT:
Enter the no. of nodes: 5
0 0 1 0 0
1 0 0 1 0
0 0 0 0 1
0 0 1 0 1
0 0 0 0 0
Solution:1 3 0 2 4
