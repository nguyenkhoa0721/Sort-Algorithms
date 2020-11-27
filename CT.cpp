#include<iostream>
#include<algorithm>
#include <time.h>
#include <fstream>
using namespace std;
int *a = new int[300000];
int *b = new int[300000];
clock_t Caltime;
template <class T>
void Swap(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}
void SelectionSort(int a[], int n)
{
	int min_idx;
	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < n; j++)
		if (a[j] < a[min_idx])
			min_idx = j;
		Swap(a[min_idx], a[i]);
	}
}
void InsertionSort(int a[], int n)
{
	int t, j;
	for (int i = 1; i<n; i++)
	{
		j = i - 1;
		t = a[i];
		while (j >= 0 && t < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t; 
	}
}
int findPos(int a[], int val, int l, int r)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == val) return mid + 1;
		if (a[mid] < val) l = mid + 1;
		if (a[mid]>val) r = mid - 1;
	}
	return l;
}
void BinaryInsertionSort(int a[], int n)
{
	int t, j;
	for (int i = 1; i<n; i++)
	{
		j = i - 1;
		t = a[i];
		int pos = findPos(a, t, 0, j);
		while (j >= pos)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}
void BubbleSort(int a[], int n) 
{
	for (int i = 0; i < n - 1; i++) 
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}
void ShakerSort(int a[], int n)
{
	bool Swapped = true;
	int start = 0;
	int end = n - 1;

	while (Swapped)
	{
		Swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				Swapped = true;
			}
		}

		if (!Swapped)
			break;

		Swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i)
		{
			if (a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				Swapped = true;
			}
		}
		++start;
	}
}
void ShellSort(int a[], int n) //gfg
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}
void shift(int a[], int l, int r)
{
	int x = a[l];
	int i = l,j=2*i+1;
	while (j <= r)
	{
		if (j<r&&a[j] < a[j + 1]) j++;
		if (a[j] <= x) break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = x;
}
void HeapSort(int a[], int n)
{
	int l = n / 2;
	while (l >= 0)
	{
		shift(a, l, n - 1);
		l--;
	}
	int r = n - 1;
	while (r > 0)
	{
		Swap(a[0], a[r]);
		r--;
		shift(a, 0, r);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L=new int [n1], *R=new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete []L;
	delete []R;
}
void MergeSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r - 1) / 2;
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}
void QuickSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	
	Swap(a[(l + r) / 2], a[l]);
	int p = a[l];
	int i = l;
	int j = r + 1;
	do{
		do i++; while (a[i] <= p&&i<=r+1);
		do j--; while (a[j] >= p&&j>l);
		Swap(a[i], a[j]);
	} while (i < j);
	Swap(a[i], a[j]);
	Swap(a[l], a[j]);
	QuickSort(a, l, j - 1);
	QuickSort(a, j + 1, r);
}
void CountingSort(int a[], int n)
{
	int maxx=a[0];
	for (int i = 1; i < n; i++)
	{
		maxx = max(maxx, a[i]);
	}
	int *cnt = new int[maxx+1];
	for (int i = 0; i <= maxx; i++)
		cnt[i] = 0;
	int *kq = new int[n];
	for (int i = 0; i < n; i++)
	{
		++cnt[a[i]];
	}
	for (int i = 1; i <= maxx; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		kq[cnt[a[i]] - 1] = a[i];
		cnt[a[i]]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = kq[i];
	delete[] kq;
	delete[] cnt;
}
void countSort(int a[], int n, int exp)
{
	int *kq=new int[n]; 
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) 
	{
		kq[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = kq[i];
	delete[] kq;
}
void RadixSort(int a[], int n)
{
	int maxx = -1;
	for (int i = 0; i < n; i++)
		maxx = max(maxx, a[i]);
	for (int exp = 1; maxx / exp > 0; exp *= 10)
		countSort(a, n, exp);
}
void FlashSort(int a[], int n)
{
	int m = n*0.43;
	int minn = a[0];
	int maxx = a[0];
	for (int i = 1; i < n; i++)
	{
		minn = min(minn, a[i]);
		maxx = max(maxx, a[i]);
	}
	int *L = new int[m+1];
	for (int i = 0; i <= m; i++)
		L[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int k = (m - 1)*(a[i] - minn) / (maxx - minn) + 1;
		L[k]++;
	}
	for (int i = 2; i <= m; i++)
		L[i] += L[i - 1];
	int cnt = 0, i = 0, k = m;
	while (cnt < n-1)
	{
		while (i>L[k]-1)
		{
			i++;
			k = (m - 1)*(a[i] - minn) / (maxx - minn) + 1;
		}
		int x = a[i];
		while (i <= L[k]-1)
		{
			k = (m - 1)*(x - minn) / (maxx - minn) + 1;
			int y = a[L[k] - 1];
			a[L[k] - 1] = x;
			x = y;
			L[k]--;
			cnt++;
		}
	}
	for (k = 2; k <= m; k++)
	{
		for (int i = L[k]-2; i >= L[k - 1];i--)
		if (a[i] > a[i + 1])
		{
			int tmp = a[i];
			int j = i;
			while (tmp > a[j + 1])
				a[j++] = a[j + 1];
			a[j] = tmp;
		}
	}
	delete[] L;
}
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		Swap(a[r1], a[r2]);
	}
}
void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	
		GenerateRandomData(a, n);
		break;
	case 1:	
		GenerateSortedData(a, n);
		break;
	case 2:	
		GenerateReverseData(a, n);
		break;
	case 3:	
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void preSort(int type,int size)
{
	for (int i = 0; i < size; i++)
		a[i] = b[i];
	Caltime = clock();
}
double postSort()
{
	Caltime = clock() - Caltime;
	double rtime = Caltime / (double)CLOCKS_PER_SEC;
	rtime *= 1000;
	return rtime;
}
int main()
{
	int n, type=0;
	ofstream fo("Random.txt");
    int size[5] = { 3000, 10000, 30000, 100000, 300000 };

	for (int i = 0; i < 5; i++) 
	{
		n = size[i];
		fo << "Size= " << size[i]<<endl;
		GenerateData(b, size[i], type);

		preSort(type, size[i]);
		SelectionSort(a, n);
		fo<<"Sl "<<postSort()<<endl;

		preSort(type, size[i]);
		InsertionSort(a, n);
		fo<<"Is "<<postSort()<<endl;

		preSort(type, size[i]);
		BinaryInsertionSort(a, n);
		fo<<"Bi "<<postSort()<<endl;

		preSort(type, size[i]);
		BubbleSort(a, n);
		fo<<"Bb "<<postSort()<<endl;

		preSort(type, size[i]);
		ShakerSort(a, n);
		fo<<"Sk "<<postSort()<<endl;

		preSort(type, size[i]);
		ShellSort(a, n);
		fo<<"Sh "<<postSort()<<endl;

		preSort(type, size[i]);
		HeapSort(a, n);
		fo<<"He "<<postSort()<<endl;

		preSort(type, size[i]);
		MergeSort(a, 0, n - 1);
		fo<<"Mg "<<postSort()<<endl;

		preSort(type, size[i]);
		QuickSort(a, 0, n - 1);
		fo<<"QS "<<postSort()<<endl;

		preSort(type, size[i]);
		CountingSort(a, n);
		fo<<"Ct "<<postSort()<<endl;

		preSort(type, size[i]);
		RadixSort(a, n);
		fo<<"Rd "<<postSort()<<endl;

		preSort(type, size[i]);
		FlashSort(a, n);
		fo<<"Fl "<<postSort()<<endl;
		fo << endl;
		cout << size[i] << endl;
	}
	delete[]a;
	delete[]b;
	fo.close();
	return 0;
}