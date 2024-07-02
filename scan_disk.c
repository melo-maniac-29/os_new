#include<stdio.h>
#include<stdlib.h>
void scan(int Ar[20], int n, int start);
void sort(int Ar[20], int n);
void main() {
int q[20], n, start, i,c;
printf("Enter the size of Queue: ");
scanf("%d", &n);
printf("Enter the Queue: ");
for(i=1;i<=n;i++) { 
scanf("%d",&q[i]);
}
printf("Enter the initial head position: ");
scanf("%d", &start);
printf("Enter the total number of cylinders: ");
scanf("%d", &c);
q[n+1]=c-1;
n=n+1;
q[0] = start; 
++n;
sort(q, n); 
scan(q, n, start);
}

void scan(int Ar[20], int n, int start) {
    int i, pos, diff, st=0, current;
    for(i=0;i<n;i++) {
        if(Ar[i]==start) {
        pos=i;
        break;
        }
    }
    printf("\nMovement of Cylinders\n");
    for(i=pos;i<n-1;i++) {
    diff = abs(Ar[i+1] - Ar[i]);
    st += diff;
    printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
    }
    current=i; 
    for(i=pos-1;i>=0;i--) {
    diff = abs(Ar[current] - Ar[i]);
    st += diff;
    printf("Move from %d to %d with seek time %d\n", Ar[current], Ar[i], diff);
    current=i;
    }
    printf("\nTotal Seek Time: %d", st);
    printf("\n");
}
void sort(int Ar[20], int n) {
int i, j, tmp;
for(i=0;i<n-1;i++) {
    for(j=0;j<n-1-i;j++) {
        if(Ar[j]>Ar[j+1]) {
        tmp = Ar[j];
        Ar[j] = Ar[j+1];
        Ar[j+1] = tmp;
        }
    }
}
}