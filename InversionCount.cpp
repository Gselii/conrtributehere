#include<bits/stdc++.h>
using namespace std;

//function to print array
void print_arr(long long a[],long long n){
  for(long long i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

long long cnt=0;

//merge with count inversion
void merge(long long a[],long long l, long long r, long long m){
  long long i=l,j=m+1,k=0,n=r-l+1;
  long long t[n];
  while(i<=m&&j<=r){
    if(a[i]>a[j]){
      t[k]=a[j];
      cnt+=(m-i+1);
      k++; j++;
    }

    else t[k++]=a[i++];
  }

  while(i<=m){
    t[k++]=a[i++];
  }

  while(j<=r)
    t[k++]=a[j++];

  for(long long x=l;x<=r;x++){
    a[x]=t[x-l];
  }

}

//merge sort
void mergeSort(long long a[],long long l,long long r){
  if(l>=r) return;
  long long m=(l+r)/2;
  mergeSort(a,l,m);
  mergeSort(a,m+1,r);
  merge(a,l,r,m);

}


int main(){
  long long n;
  cin>>n;
  long long a[n];
  for(long long i=0;i<n;i++)
    cin>>a[i];
  cout<<"INPUT\n";
  print_arr(a,n);

  mergeSort(a,0,n-1);

  cout<<"Sorted Array: "
  print_arr(a,n);
  cout<<"Inversion Count: "<<cnt;
  return 0;
}
