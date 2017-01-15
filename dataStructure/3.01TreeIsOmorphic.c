#include <stdio.h>//PTA.3.01 ¡£Ê÷µÄÍ¬¹¹

#define OK 1
#define error 0
#define MaxTree 10
#define Null -1

typedef char ElementType;
typedef int Status;

typedef struct TreeNode{
    ElementType data;
    int left;
    int right;
}Tree;

Tree T1[MaxTree],T2[MaxTree];

int BuildTree(Tree T[])
{
    int i,N,root=Null;
    int check[MaxTree];
    char cl,cr;

    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        check[i]=1;
    }
    for(i=0;i<N;i++)
    {
        if(N)
        {
            scanf("%c %c %c\n",&T[i].data,&cl,&cr);
            if(cl!='-')
            {
                T[i].left=cl-'0';
                check[T[i].left]=0;
            }
            else
            {
                T[i].left=Null;
            }
            if(cr!='-')
            {
                T[i].right=cr-'0';
                check[T[i].right]=0;
            }
            else
            {
                T[i].right=Null;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        if(check[i])
        {
            root=i;
        }
    }


    return root;
}

Status isOmorphic(Status root1,Status root2)
{
    if(root1==Null&&root2==Null)
    {
        return OK;
    }
    if((root1==Null)&&(root2!=Null)||(root1!=Null)&&(root2==Null))
    {
        return error;
    }
    if(T1[root1].data!=T2[root2].data)
    {
        return error;
    }
    if((T1[root1].left==Null)&&(T2[root2].left==Null))
    {
        return isOmorphic(T1[root1].right,T2[root2].right);
    }
    if((T1[root1].left!=Null)&&(T2[root2].left!=Null)&&(T1[T1[root1].left].data==T2[T2[root2].left].data))
    {
        return (isOmorphic(T1[root1].left,T2[root2].left)&&isOmorphic(T1[root1].right,T2[root2].right));
    }
    else
    {
        return (isOmorphic(T1[root1].left,T2[root2].right)&&isOmorphic(T1[root1].right,T2[root2].left));
    }
}

int main()
{
    int root1,root2;
    root1=BuildTree(T1);
    root2=BuildTree(T2);
    if(isOmorphic(root1,root2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
