
#include &lt;stdio.h&gt;
int cost[10][10], n, t[10][2], sum;
void prims(int cost[10][10], int n);
int main() {
int i, j;
printf(&quot;Enter the number of vertices: &quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter the cost adjacency matrix:\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
scanf(&quot;%d&quot;, &amp;cost[i][j]);
}
}
prims(cost, n);
printf(&quot;Edges of the minimal spanning tree:\n&quot;);
for (i = 0; i &lt; n - 1; i++) {
printf(&quot;(%d, %d) &quot;, t[i][0], t[i][1]);
}
printf(&quot;\nSum of minimal spanning tree: %d\n&quot;, sum);
return 0;
}
void prims(int cost[10][10], int n) {
int i, j, u, v;
int min, source;
int p[10], d[10], s[10];
min = 999;
source = 0;

// Initialize arrays
for (i = 0; i &lt; n; i++) {
d[i] = cost[source][i];
s[i] = 0;
p[i] = source;
}
s[source] = 1;
sum = 0;
int k = 0;
// Find MST
for (i = 0; i &lt; n - 1; i++) {
min = 999;
u = -1;
// Find the vertex with minimum distance to the MST
for (j = 0; j &lt; n; j++) {
if (s[j] == 0 &amp;&amp; d[j] &lt; min) {
min = d[j];
u = j;
}
}
if (u != -1) {
// Add edge to MST
t[k][0] = u;
t[k][1] = p[u];
k++;
sum += cost[u][p[u]];
s[u] = 1;
// Update distances
for (v = 0; v &lt; n; v++) {
if (s[v] == 0 &amp;&amp; cost[u][v] &lt; d[v]) {
d[v] = cost[u][v];
p[v] = u;
}
}
}

}
}


OUTPUT:
Enter the number of vertices: 4
Enter the cost adjacency matrix:
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0
Edges of the minimal spanning tree:
(1, 0) (3, 0) (2, 3)
Sum of minimal spanning tree: 6



  
KRUSKAL'S ALGORITHM

#include &lt;stdio.h&gt;
int cost[10][10], n, t[10][2], sum;
void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);
int main() {
int i, j;
printf(&quot;Enter the number of vertices: &quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter the cost adjacency matrix:\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
scanf(&quot;%d&quot;, &amp;cost[i][j]);
}
}
kruskal(cost, n);
printf(&quot;Edges of the minimal spanning tree:\n&quot;);

for (i = 0; i &lt; n - 1; i++) {
printf(&quot;(%d, %d) &quot;, t[i][0], t[i][1]);
}
printf(&quot;\nSum of minimal spanning tree: %d\n&quot;, sum);
return 0;
}
void kruskal(int cost[10][10], int n) {
int min, u, v, count, k;
int parent[10];
k = 0;
sum = 0;
// Initialize parent array for Union-Find
for (int i = 0; i &lt; n; i++) {
parent[i] = i;
}
count = 0;
while (count &lt; n - 1) {
min = 999;
u = -1;
v = -1;
// Find the minimum edge
for (int i = 0; i &lt; n; i++) {
for (int j = 0; j &lt; n; j++) {
if (find(parent, i) != find(parent, j) &amp;&amp; cost[i][j] &lt; min) {
min = cost[i][j];
u = i;
v = j;
}
}
}
// Perform Union operation
int root_u = find(parent, u);
int root_v = find(parent, v);

if (root_u != root_v) {
parent[root_u] = root_v;
t[k][0] = u;
t[k][1] = v;
sum += min;
k++;
count++;
}
}
}
int find(int parent[10], int i) {
while (parent[i] != i) {
i = parent[i];
}
return i;
}


OUTPUT:
Enter the number of vertices: 4
Enter the cost adjacency matrix:
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0
Edges of the minimal spanning tree:
(1, 0) (3, 0) (2, 3)
Sum of minimal spanning tree: 6

