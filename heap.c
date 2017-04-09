#include<stdio.h>
#include<stdlib.h>

int h=0;

void maxheapify(int a[],int n,int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int max=i,temp;
	//if(i>=n/2)
	//	return;
	if(l<h && a[l]>a[i])
	{	max=l;
	    //printf("%d\n",max);
	}
	//printf("%d\n",max);
	if(r<h && a[r]>a[max])
		max=r;
	//printf("%d\n",max);
	if(max!=i)
	{
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		maxheapify(a,n,max);
	}
}

/*void maxheapify(int *a,int n,int i)
{
  int l,r,smallest,temp;
  l=2*i+1;
  r=2*i+2;
  if(l<n && a[l]>a[i])
  {
      smallest=l;
  }
  else
  {
      smallest=i;
  }
  if(r<n && a[r]>a[smallest])
  {
      smallest=r;
  }
  if(smallest!=i)
  {
      temp=a[i];
      a[i]=a[smallest];
      a[smallest]=temp;
      maxheapify(a,n,smallest);
  }
}*/

void buildheap(int a[],int n)
{
	int i;
	//printf("%d\n",i);
	int m=h/2-1;
	for(i=m;i>=0;i--)
		{
			//printf("%d\t",a[i]);
			printf("%d\n",i);
			
			maxheapify(a,n,i);
		}
}

int extractmax(int a[],int n)
{
	int max;
	if(h<1)
		return;
	max=a[0];
	a[0]=a[h-1];
	h=h-1;
	maxheapify(a,n,0);
	return max;
}

void increasekey(int a[],int n,int i,int key)
{
	a[i]=key;
	int temp;
	while(a[i]>a[(i-1)/2]&&i>=1)
	{
		temp=a[i];
		a[i]=a[(i-1)/2];
		a[(i-1)/2]=temp;
		i=(i-1)/2;
	}
}

void insert(int a[],int n,int key)
{
	//a=(int*)realloc(a,n+1);
	h=h+1;
	a[h-1]=key;
	int i=h-1,temp;
	while(a[i]>a[(i-1)/2]&&i>0)
	{
		
		temp=a[i];
		a[i]=a[(i-1)/2];
		a[(i-1)/2]=temp;
		i=(i-1)/2;
	}
}

void heapsort(int a[],int n)
{
	int i,temp;
	h=n;
	for(i=h/2-1;i>=0;i--)
	{
		maxheapify(a,n,i);
	}
	while(h>0)
	{
		temp=a[0];
		a[0]=a[h-1];
		a[h-1]=temp;
		h--;
		maxheapify(a,i,0);
	}
}

int main()
{
	int n=8;
	int i,res,t;
	int* a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			insert(a,n,t);
		}
	//buildheap(a);
	printf("heap:\n");
	for(i=0;i<h;i++)
		printf("%d\t",a[i]);
	printf("\n");
	//res=extractmax(a,n);
	//printf("Extract max :%d\n",res);
	heapsort(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	/*increasekey(a,n,3,30);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	insert(a,n,300);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");*/

}