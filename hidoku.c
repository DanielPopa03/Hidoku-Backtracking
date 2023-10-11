#include <stdio.h>
#include <stdlib.h>
struct aux{
int val;
int i,j;
}*checkpoints;
int **m;
int  nr_check,cur,n,ramase;
int pasi=0;
int cmp(const void *x_void, const void *y_void) {
    struct aux *x = (struct aux *)x_void;
    struct aux *y = (struct aux *)y_void;
    return x->val - y->val;
}
void altafunctie(int a);
void hidoku();
int main(){
    int k,i,j;
    FILE *f=fopen("fil.in","r");
    fscanf(f,"%d",&n);
    m=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        m[i]=(int *)calloc(n,sizeof(int));
    }
    fscanf(f,"%d",&nr_check);
    checkpoints=(struct aux *)malloc(nr_check*sizeof(struct aux));
    for(i=0;i<nr_check;i++){
    fscanf(f,"%d %d %d",&checkpoints[i].val,&checkpoints[i].i,&checkpoints[i].j);
        m[checkpoints[i].i][checkpoints[i].j]=checkpoints[i].val;
    }
    //for(i=0;i<nr_check;i++)
    //printf("%d|",checkpoints[i].val);
    //printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        printf("%2d ",m[i][j]);
        printf("\n");
    }
    ramase=checkpoints[1].val-1-checkpoints[0].val;
    cur=1;
    hidoku(checkpoints[0].i,checkpoints[0].j,checkpoints[0].val);
    printf("\n %d ",pasi);
    for( i=0;i<n;i++)
    free(m[i]);
    free(m);
    return 0;
}
void hidoku(int i,int j,int val){
    pasi+=1;
    if(ramase!=0){
    for(int k=i-1;k<=i+1;k++){
        if(k<0 || k>n-1)continue;
        for(int z=j-1;z<=j+1;z++){
            if(z<0 || z>n-1)continue;
            if(m[k][z]!=0)continue;
            m[k][z]=val+1;
            ramase--;
            hidoku(k,z,val+1);
            ramase++;
            m[k][z]=0;
            }
        }
        return;
    }
    else{
        if(cur!=nr_check-1){
        for(int k=i-1;k<=i+1;k++){
        if(k<0 || k>n-1)continue;
        for(int z=j-1;z<=j+1;z++){
            if(z<0 || z>n-1)continue;
            
            if(m[k][z]==val+1){
                cur+=1;
                ramase=checkpoints[cur].val-checkpoints[cur-1].val-1;
                hidoku(checkpoints[cur-1].i,checkpoints[cur-1].j,checkpoints[cur-1].val);
                ramase=0;
                cur-=1;
            }
          }
        }
        return;
        }
        else{
            for(int k=i-1;k<=i+1;k++){
                if(k<0 || k>n-1)continue;
                for(int z=j-1;z<=j+1;z++){
                    if(z<0 || z>n-1)continue;
                    if(m[k][z]==n*n){printf("\n");
                        for(i=0;i<n;i++){
                            for(j=0;j<n;j++)
                            printf("%2d ",m[i][j]);
                            printf("\n");
                        }            
                    }
                }
            }
            return;
        }
    }
}