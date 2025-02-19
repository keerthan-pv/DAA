#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 10

int n,graph[MAX][MAX];
int minCost=INT_MAX;
int bestPath[MAX+1],tempPath[MAX+1];
bool isLexSmaller(int path1[ ],int path2[ ]){
    for(int i =0; i<=n;i++){
        if (path1[i]<path2[i])return true;
        if (path1[i]>path2[i])return false;}
    return false;}
void tsp(int level,int currCost,bool visited[ ]){
    if (level == n){
        if (graph[tempPath[n-1]][tempPath[0]]!=-1){
            int totalCost= currCost +graph[tempPath[n-1]][tempPath[0]];
            if (totalCost< minCost||(totalCost==minCost&&isLexSmaller(tempPath, bestPath))){
                minCost=totalCost;
                for(int i= 0;i < n;i++) bestPath[i]=tempPath[i];
                bestPath[n]=tempPath[0];}}
        return;
    }
    for(int i = 1; i < n; i++){
        if (!visited[i] && graph[tempPath[level - 1]][i] != -1){
            visited[i]=true;
            tempPath[level]=i;
            tsp(level+1,currCost+graph[tempPath[level-1]][i],visited);
            visited[i] = false;}}
            }

int main(){
    scanf("%d",&n);
    for (int i=0;i <n;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    bool visited[MAX]={false};
    tempPath[0]=0;
    visited[0]=true;

    tsp(1,0,visited);

    if(minCost==INT_MAX){
        printf("Path does not exist\n");
    }else{
        printf("Minimum Cost: %d\nOptimal Path: ",minCost);
        for (int i = 0; i <= n; i++) printf("%d ",bestPath[i]);
        printf("\n");
    }
    return 0;
}