#include<iostream.h> 
#include<conio.h> 
class DataArray
{
protected:
int a[100],n; public:
int Getn(void) { return n; } void GetData(void);
void Display(void);
};

void DataArray::GetData(void)
{
cout<<"\n Enter the number of elements to be sorted : "; cin>>n;
for(int i=0;i<n;i++)
{
cout<<" Enter element no. "<<i+1<< " :"; cin>>a[i];
}
}

void DataArray::Display(void)
{
for(int i=0;i<n;i++) cout<<" "<<a[i]; cout<<endl;
}

class Merging : public DataArray
{
public:
void Merge(int low, int high, int mid); void MergeSort(int low, int high); void MergeDisplay(int l,int h);
};
 

void Merging::MergeSort(int low, int high)
{
int mid; if(low<high)
{
mid=(low+high)/2;
cout<<"Dividing :";	MergeDisplay(low,mid); MergeSort(low,mid);
cout<<"Dividing :";	MergeDisplay(mid+1,high); MergeSort(mid+1,high);
cout<<"Merging list 1 :";	MergeDisplay(low,mid); cout<<"Merging list 2 :";	MergeDisplay(mid+1,high);
Merge(low,high,mid);
cout<<"After merging :";	MergeDisplay(low,high);
}
}

void Merging::Merge(int low, int high, int mid)
{
int i, j, k, c[50]; i=low; j=mid+1; k=low;
while((i<=mid)&&(j<=high))
{
if(a[i]<a[j])
{
c[k]=a[i]; k++; i++;
}
else
{
c[k]=a[j]; k++; j++;
}
}
while(i<=mid)
{
c[k]=a[i]; k++; i++;
}
while(j<=high)
{
c[k]=a[j]; k++; j++;
 
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}

void Merging::MergeDisplay(int l,int h)
{
for(int i=l;i<=h;i++) cout<<" "<<a[i]; cout<<endl;
}

int main()
{
Merging M; clrscr();
M.GetData();	cout<<"Dividing :";	M.MergeDisplay(0,M.Getn()-1); M.MergeSort(0,M.Getn()-1);
cout<<"\n\t The Sorted Array"; cout<<"\n\t ~~~~~~~~~~~~~~~~\n"; M.Display();
getch(); return 0;
}
