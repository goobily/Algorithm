#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	if(a == b)
		return;
	int temp = a;
	a = b;
	b = temp;
}

/*         quicksort   不稳定       */
/*************************************************/
int partition(int X[],int p, int r)
{
	int i=p-1;
	int j=p;
	while(j<r)
	{
		if(X[j] <= X[r])
		{
			swap(X[++i], X[j]);
		}
		++j;
	}
	swap(X[i+1], X[r]);
	return i+1;
}

void quicksort(int X[], int left, int right)
{
	int p;
	if(left < right)
	{
		p = partition(X, left, right);
		quicksort(X, left, p-1);
		quicksort(X, p+1, right);
	}
}
/*************************************************/

/*         heapsort    不稳定      */
/*************************************************/
void heap_up(int arr[], int n)
{
	int i;
	int *heap = new int[n+1];
	for( i=1; i<=n; ++i)
		heap[i] = arr[i-1];

	 i = n;
	while(1)
	{
		if(i == 1) break;
		int p = i / 2;
		if(heap[p] <= heap[i]) break;
		swap(heap[p], heap[i]);
		i = p;
	}
	for( i=0; i<n; ++i)
		arr[i] = heap[i+1];
	delete[] heap;
}

void heap_down(int arr[], int n)
{
	int i;
	int *heap = new int[n+1];
	for( i=1; i<=n; ++i)
		heap[i] = arr[i-1];
	i = 1;
	while(1)
	{
		int c = 2*i;
		if(c > n) break;
		if(c+1 <= n)
			if(heap[c+1] < heap[c])
				++c;
		if(heap[i] <= heap[c]) break;
		swap(heap[i], heap[c]);
		i = c;
	}
	for( i=0; i<n; ++i)
		arr[i] = heap[i+1];
	delete[] heap;
}

void heapsort(int arr[], int n)
{
	int i;
	for(i=2; i<=n; ++i)
		heap_up(arr,i);
	for(i=n; i>1; --i)
	{
		swap(arr[0], arr[i-1]);
		heap_down(arr, i-1);
	}
	for(i=n-1; i>=0; --i)
		cout<<arr[i] <<" ";
	cout<<endl;
	
}
/*************************************************/

/*         insertionsort    稳定      */
/*************************************************/
void insertsort(int arr[], int n)
{
	for(int i=1; i<n; ++i)
	{
		int key = arr[i];
		int j = i-1;
		while(j >=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}
/*************************************************/

/*         bubsort     稳定     */
/*************************************************/
void bubsort(int arr[], int n)
{
	bool flag = true;
	for(int i=0; i<n-1 && flag; ++i)
	{
		flag = false;
		for(int j=0; j<n-1-i ; ++j)
		{
			if(arr[j +1] < arr[j])
			{
				swap(arr[j+1], arr[j]);
				flag = true;
			}
		}
	}	
}
/*************************************************/

/*         selsort    不稳定      */
/*************************************************/
void selsort(int arr[], int n)
{
	for(int i=0; i<n-1; ++i)
	{
		int m = i;
		for(int j=i+1; j<n; ++j)
		{
			if(arr[j] < arr[m])
				m = j;
		}
		if(i != m)
			swap(arr[i], arr[m]);
	}
}
/*************************************************/

/*         mergesort    稳定      */
/*************************************************/
void merge(int arr[], int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int *Larr = new int[n1+1];
	int *Rarr = new int[n2+1];
	for(int i=0; i<n1; ++i)
		Larr[i] = arr[p+i];
	for(int j=0; j<n2; ++j)
		Rarr[j] = arr[q+j+1];
	Larr[n1] = INT_MAX;
	Rarr[n2] = INT_MAX;
	int i = 0; int j = 0;
	for(int k=p; k<=r; ++k)
	{
		if(Larr[i] <= Rarr[j])
		{
			arr[k] = Larr[i]; 
			++i;
		}
		else
		{
			arr[k] = Rarr[j];
			++j;
		}
	}
	delete[] Larr;
	delete[] Rarr;
}

void mergesort(int arr[], int p, int r)
{
	if(p < r)
	{
		int q = (p+r) / 2;
		mergesort(arr, p, q);
		mergesort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}
/*************************************************/


/*         shellsort    不稳定      */
/*************************************************/
void shellsort(int a[], int n)
{
	int i,j,k;
	int gap = n / 2;
	while(gap > 0)
	{
		for(k=0; k<gap; ++k)
		{
			for(i=k+gap; i<n; i+=gap)
			{
				for(j=i-gap; j>=k; j-=gap)
				{
					if(a[j] > a[j+gap])
						swap(a[j],a[j+gap]);
					else 
						break;
				}
			}
		}
		gap /= 2;
	}
}

void shellsort_v2(int a[], int n)
{
	int gap = n/2;
	while(gap > 0) 
	{
		for(int i=0; i<gap; ++i)
		{
			for(int j=i+gap; j<n; j+=gap)
			{
				int tmp = a[j];
				int k = j-gap;
				while(k>=i && tmp < a[k]) {
					a[k+gap] = a[k];
					k -= gap;
				}
				a[k+gap] = tmp;
			}
		}
		gap /= 2;
	}
}

void shellpass(int a[], int n, int gap)
{
	for(int i=gap; i<n; ++i)
	{
		int tmp = a[i];
		int j = i-gap;
		while(j>=0 && a[j] > tmp)
		{
			a[j+gap] = a[j];
			j -= gap;
		}
		a[j+gap] = tmp;
	}
}

void shellsort_v3(int a[], int n)
{
	int gap = n;
	while(gap > 1)
	{
		gap = gap/3+1;
		shellpass(a,n,gap);
	}
}
/*************************************************/
int main()
{
	/*int numSize;
	cin>>numSize;
	int *arr = new int[numSize];
	for(int i=0; i<numSize; ++i)
	cin>>arr[i] ;*/

	//quicksort(arr, 0, numSize-1);

	//heapsort(arr, numSize);

	//insertsort(arr, numSize);

	//bubsort(arr, numSize);

	//selsort(arr, numSize);

	//mergesort(arr, 0, numSize-1);

	int arr[] = {1,2,3,1,2,3,6,7,4,2};
	int numSize = sizeof(arr) / sizeof(arr[0]);
	for(int i=0; i<numSize; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	heapsort(arr,numSize);

	for(int i=0; i<numSize; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}