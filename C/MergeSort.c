#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create(int arr[],int n)
{
	int i;
	printf("\n Enter %d elements : ",n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);	
	
}

void display(int arr[],int low, int n)
{
	int i;
	static int pass=1;
	printf("\n Array after pass %d \n", pass);
	for (i=low;i<n;i++)
		printf("%d \t", arr[i]);
	pass++;
}

void swap(int *x, int *y) {

   int temp;
   temp = *x; 
   *x = *y;      
   *y = temp;   
  
}

void merge(int array[], int lb, int mid, int ub, int n)
{
	int i,j,k;
	int a = mid - lb + 1;
	int b = ub - lb;
	
	int b_array[a], c_array[b];
	for(i=0; i<a; i++)
		b_array[i] = array[lb + i];
	
	for(j=0; j< b; j++)
		c_array[j] = array[mid + 1 + j];
	
	i = 0;
	j = 0;
	k = lb;
	
	while(i< a && j < b)
	{
		if(b_array[i] <= c_array[j] )
		{
			array[k] = b_array[i];
			i++;
		}
		else
		{
			array[k] = c_array[j];
			j++;
		}
		k++;
	}
	while(i < a)
	{
		array[k] = b_array[i];
		i++;
		k++; 
	}
	while(j < b)
	{
		array[k] = c_array[j];
		j++;
		k++;
	}
	display(array,0,n);
}


void merge_sort(int array[], int lb, int ub, int n)
{  
	if(lb < ub)
	{
		int mid = lb + (ub -lb)/2;
		merge_sort(array, lb, mid,n);
		merge_sort(array, mid+1, ub,n);
		merge(array, lb,mid, ub,n);   	
	}
}


int main()
{	char ans='Y';
	int n;
	printf("\n Enter the size of the array(must be less than/equal to 50 ) : ");
	scanf("%d",&n);
	clock_t t;
	t=clock();
	if(n>50)
		printf("\n Out of bound ");
	else
	{	int arr[n]; 
		create (arr,n);
		merge_sort(arr,0,n-1,n);
	    display(arr,0, n);
		
	}
	t=clock()-t;
	printf("\nRunning Time of Merge Sort : %lf", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}
	

