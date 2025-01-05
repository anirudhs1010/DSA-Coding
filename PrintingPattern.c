#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//https://www.hackerrank.com/challenges/printing-pattern-2/problem
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Special case for n=1
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    
    int size = 2*n - 1;
    // For each row
    for(int i = 0; i < size; i++) {
        // For each column
        for(int j = 0; j < size; j++) {
            // Find the minimum distance to an edge
            int min_dist = min(min(i, j), min(size-1-i, size-1-j));
            // Print n - minimum distance
            printf("%d ", n - min_dist);
        }
        printf("\n");
    }
    return 0;
}
