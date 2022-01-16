#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int count;
    int data;
    struct node *next;
}node;

node *first1,*first2,*first3;
node *temp1,*temp2,*temp3;

int disk;

node *ins_f(node *first,int data)
{

    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=first;
        first=newnode;
    return first;
}


FILE * printt(int data,FILE *f)
{
    //q=fopen("output.txt","a");
    if(data==0)
    {
        printf("...................\t\t");
        fprintf(f,"...................\t\t");
    }

    else
    {
        printf("{&&&&&&& %d &&&&&&&}\t\t",data);
        fprintf(f,"{&&&&&&& %d &&&&&&&}\t\t",data);
    }
    return f;
}
void dis()
{
    FILE *f;

    f=fopen("output","a+");
    temp1=(node *)malloc(sizeof(node));
    temp2=(node *)malloc(sizeof(node));
    temp3=(node *)malloc(sizeof(node));
    temp1=first1;
    temp2=first2;
    temp3=first3;

    while((temp1)!=NULL)
    {
       printf("\n");
       fprintf(f,"\n");
        f=printt(temp1->data,f);
        f=printt(temp2->data,f);
        f=printt(temp3->data,f);
        temp1=temp1->next;
        temp2=temp2->next;
        temp3=temp3->next;

    }
    fclose(f);
    f=fopen("output","a+");
    printf("\n");
  // printf(f,"\n");
    printf("      SOURCE");
    fprintf(f,"\n      SOURCE");
    printf("------------------------");
    fprintf(f,"------------------------");
    printf("AUXILARY");
    fprintf(f,"AUXILARY");
    printf("-----------------------");
    fprintf(f,"----------------------");
    printf("DESTINATION");
    fprintf(f,"DESTINATION");
        printf("\n\n\n");
    fprintf(f,"\n\n\n");
    fclose(f);
}

void picker(node *first,int peg)
{
     node *temp;
    temp =(node *)malloc(sizeof(node));
    temp=first;
    while(temp->data!=peg)
        temp=temp->next;
            temp->data=0;
//return tempo;
}

void placer(node *first,int peg)
{
  node *temp,*perv;
  perv=(node *)malloc(sizeof(node));
  perv=NULL;
    temp =(node *)malloc(sizeof(node));
   temp=first;
   while((temp->next!=NULL)&&(temp->data<peg))
   {
       perv=temp;
        temp=temp->next;
   }
   if(temp->data>perv->data)
      perv->data=peg;
   else
    temp->data=peg;
}

void mover(char src, char des, int peg)
{

    switch(src)
    {
    case 'A':
            picker(first1,peg);
            break;
    case 'B':
            picker(first2,peg);
            break;
    case 'C':
            picker(first3,peg);
            break;
    }
switch(des)
    {
    case 'A':
            placer(first1,peg);
            break;
    case 'B':
            placer(first2,peg);
            break;
    case 'C':
            placer(first3,peg);
            break;
    }
    dis();
}
void toh(int n,char sr,char au, char de,int data)
{

    if(n==1)
       {
        printf("\n%d FROM SOURCE TO DESTINATION %c to %c",n,sr,de);
        mover(sr,de,n);
        return;
       }
toh(n-1,sr,de,au,data);
    printf("\n%d FROM SOURCE TO DESTINATION %c to %c:",n,sr,de);
   mover(sr,de,n);
    toh(n-1,au,sr,de,data);
}
int main()
{
    FILE *f;
    f=fopen("output","a");
    int data;
    int i;

    first1=(node *)malloc(sizeof(node));
    first2=(node *)malloc(sizeof(node));
    first3=(node *)malloc(sizeof(node));
    first1=NULL;
    first2=NULL;
    first3=NULL;
    printf("NUMBER OF DISKS PLEASE:");
    scanf("%d",&disk);
    fprintf(f,"---------------------------------------------------");
    fprintf(f,"TOWER OF HANOI FOR %d DISK",disk);
    fprintf(f,"---------------------------------------------------\n\n\n");
    fclose(f);

    for(i=disk;i>0;i--)
    {
        data=i;
        first1 =ins_f(first1,data);
        first2=ins_f(first2,0);
        first3=ins_f(first3,0);
    }
    dis();
    toh(disk,'A','B','C',data);
    printf("ended\n");


    printf("Hello world!\n");
    return 0;
}
