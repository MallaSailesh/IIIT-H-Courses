#include<stdio.h>
#include<limits.h>
typedef long long ll;
 
int heap[1000000], heap_size;

void createheap() {
    heap_size = 0;
    heap[0] = -INT_MAX;
}
 
void insertkey(int element) {
    heap_size++;
    heap[heap_size] = element; 
    int parent = heap_size;
    while (heap[parent / 2] > element) {
        heap[parent] = heap[parent / 2];
        parent /= 2;
    }
    heap[parent] = element;
}
 
int DeleteMin() {
    int minElement, lastElement, child, parent;
    minElement = heap[1];
    lastElement = heap[heap_size--];
    for (parent = 1; parent * 2 <= heap_size; parent = child) {
        child = parent * 2;
        if (child != heap_size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (lastElement > heap[child]) {
            heap[parent] = heap[child];
        } 
        else 
        {
            break;
        }
    }
    heap[parent] = lastElement;
    return minElement;
}
 
int main() {
    createheap();
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        insertkey(x);
    }
    ll sum=0;
    while(heap_size>1){
      ll x=DeleteMin();
      ll y=DeleteMin();
      insertkey(x+y);
      sum+=(x+y);
    }
    printf("%lld\n",sum);
    return 0;
}