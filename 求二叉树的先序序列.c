#include <stdio.h>
#include <string.h>
#define STRLEN 20

char midIter[STRLEN], postIter[STRLEN], data[STRLEN]={0};
int left[STRLEN]={0}, right[STRLEN]={0}, count=1;

int distance(int l, int r){
    return r-l;
}

int iter(int lmid, int rmid, int lpost, int rpost){
    int node = count, pmid, leftlen, rightlen;
    count++;
    data[node] = postIter[rpost];
    if(lpost > rpost)   return 0;
    if(lpost == rpost)  return node;

    pmid = strchr(midIter, postIter[rpost]) - midIter;

    leftlen = distance(lmid, pmid-1), rightlen = distance(pmid+1, rmid);
    right[node] = iter(pmid+1, rmid, rpost-1-rightlen, rpost-1);
    left[node] = iter(lmid, pmid-1, lpost, lpost+leftlen);

    return node;
}

void pre_order(int node){
    // printf("%c %d %d %d\n", data[node], node, left[node], right[node]);
    printf("%c", data[node]);
    if(left[node] != 0)     pre_order(left[node]);
    if(right[node] != 0)    pre_order(right[node]);
}

int main(){
    scanf("%s%s", midIter, postIter);
    
    int root = iter(0, strlen(postIter)-1, 0, strlen(postIter)-1);
    pre_order(root);


    return 0;
}
