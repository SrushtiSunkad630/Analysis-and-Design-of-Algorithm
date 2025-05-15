#include &lt;stdio.h&gt;
int n = 5;
int p[10] = {3, 3, 2, 5, 1};
int w[10] = {10, 15, 10, 12, 8};
int W = 10;
int main()
{
int cur_w;
float tot_v;
int i, maxi;
int used[10];
for (i = 0; i &lt; n; ++i)
used[i] = 0;
cur_w = W;
while (cur_w &gt; 0) {
maxi = -1;
for (i = 0; i &lt; n; ++i)
if ((used[i] == 0) &amp;&amp;
((maxi == -1) || ((float)w[i]/p[i] &gt; (float)w[maxi]/p[maxi])))
maxi = i;
used[maxi] = 1;
cur_w -= p[maxi];
tot_v += w[maxi];
if (cur_w &gt;= 0)
printf(&quot;Added object %d (%d, %d) completely in the bag. Space left: %d.\n&quot;, maxi + 1,
w[maxi], p[maxi], cur_w);
else {

printf(&quot;Added %d%% (%d, %d) of object %d in the bag.\n&quot;, (int)((1 +
(float)cur_w/p[maxi]) * 100), w[maxi], p[maxi], maxi + 1);
tot_v -= w[maxi];
tot_v += (1 + (float)cur_w/p[maxi]) * w[maxi];
}
}
printf(&quot;Filled the bag with objects worth %.2f.\n&quot;, tot_v);
return 0;
}

OUTPUT
Added object 5 (8, 1) completely in the bag. Space left: 9.
Added object 3 (10, 2) completely in the bag. Space left: 7.
Added object 1 (10, 3) completely in the bag. Space left: 4.
Added 80% (15, 3) of object 2 in the bag.
Filled the bag with objects worth 38.00.
