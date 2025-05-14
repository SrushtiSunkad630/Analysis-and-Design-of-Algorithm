#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
void generatePermutations(int arr[], int start, int end) {
if (start == end) {
for (int i = 0; i &lt;= end; i++) {
printf(&quot;%d &quot;, arr[i]);
}
printf(&quot;\n&quot;);
} else {
for (int i = start; i &lt;= end; i++) {
swap(&amp;arr[start], &amp;arr[i]);
generatePermutations(arr, start + 1, end);
swap(&amp;arr[start], &amp;arr[i]); // backtrack
}
}
}
int main() {
int n;
printf(&quot;Enter the number of elements: &quot;);
scanf(&quot;%d&quot;, &amp;n);

int* arr = (int*)malloc(n * sizeof(int));
printf(&quot;Enter the elements: &quot;);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;arr[i]);
}
generatePermutations(arr, 0, n - 1);
free(arr);
return 0;
}
OUTPUT:
Enter the number of elements: 4
Enter the elements: 1 2 3 4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 3 2
1 4 2 3
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 3 1
2 4 1 3
3 2 1 4
3 2 4 1
3 1 2 4
3 1 4 2
3 4 1 2
3 4 2 1
4 2 3 1
4 2 1 3
4 3 2 1
4 3 1 2
4 1 3 2
4 1 2 3
