#include<stdio.h>
int main()
{
    char tree[7] = {'A', 'B', 'C', 'D', '\0', 'F', 'G'};

    int parent_F = (5-1)/2;

    printf("%c\n", tree[parent_F]);

    return 0;
}
