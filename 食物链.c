#include <stdio.h>
#include <string.h>
#define SIZE 50001

int check_set[SIZE];
char kind[SIZE] = {0}, length[SIZE];
const int food[4] = {0, 2, 3, 1};

int find(int node){
    if(check_set[node] < 0)     return node;
    else                        return find(check_set[node]);
}

void merge(int node1, int node2){
    int left = find(node1), right = find(node2);
    if(length[left] > length[right]){
        check_set[right] = left;
        length[left] += length[right];
    }
    else{
        check_set[left] = right;
        length[right] += length[left];
    }
}

int eat(int node1, int node2){
    int left = find(node1), right = find(node2);
    if((kind[left] == 0) ^ (kind[right] == 0)){

    }
    else if(kind[left] == 0 && kind[right] == 0){
        
    }
}

int main() {
    int n, k, mode, node1, node2, fault = 0;
    memset(check_set, -1, sizeof(check_set));
    memset(length, 1, sizeof(length));
    scanf("%d%d", &n, &k);

    for(int i=0; i<k; i++){
        scanf("%d%d%d", &mode, &node1, &node2);
        if(node1 > n || node2 > n){
            fault++;
            continue;
        }

        //code
    }

    return 0;
}