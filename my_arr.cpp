#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef double dd;
#define endl '\n'
int mi=2e9; int  ma=0; const long long N = 1e5;
void Largest_Subarray(int arr[],int n)
{
    int f=0,c=0;
    int valid[n],temp[N];
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            if(arr[j]==0||arr[j]==1)
               valid [c++]=arr[j];
             else {  break;}
        }
       if(c>ma)
        {
            ma=max(ma,c);
          for(int j=0;j<ma;++j)
            temp[j]=valid[j];
        }
        c=0;
    } cout<<"Length of Subarray is "<<ma<<endl;
    for(int j=0;j<ma;++j)
           cout<<temp[j]<<" ";

}
int Max_Product(int arr[],int n)
{
   int P=1;
   ma=0;
   for(int i=0;i<n;++i)
    {    P=1;
        for(int j=i;j<n;++j)
        {   P*=arr[j];
            ma=max(P,ma);
        }

    }
    return ma;
}
void replace_greatest(int arr[],int n)
{
    int m=*max_element(arr,arr+n),f=0;
    int b[n];
    for(int i=0;i<n;++i)
    {
        b[i]=arr[i];
    }
    for(int i=0;i<n;++i)
    {
        if(b[i]==m)f=1;
        if(f==1)b[i]=m;
    }
    cout<<"Array after replace\n";
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
int max_circule(int arr[],int n)
{   int m=0,s,x=n;
    for(int i=0;i<n;++i)
    {    s=0;  x=n;
        for(int j=i;x>0;++j,x--)
        {
            s+=(arr[j]);
            if(j==n)j=-1;
        }
        m=max(m,s);
    }
    return m;
}
void Maximize(int arr[],int n)
{
    int b[n],s=0;
    for(int i=0;i<n;++i)
    {
        b[i]=arr[i];    // 1 2 4 8
    }
    sort(b,b+n);
    int c[n],j=0;
    for(int i=0;i<n/2;++i)
    {
       c[j++]=b[i];
       c[j++]=b[n-i-1];
    }
    for(int i=0;i<n;++i)
    {
        s+=abs(c[i]-c[i+1]);
    }
    cout<<"Maximize sum of consecutive differences in a circular array\n"<<s<<endl;

}
void FIND_INDX(int arr[],int n)
{
    int b[n];
    for(int i=0;i<n;++i)
    {
        b[i]=arr[i];
    }
    int index=-1,c=0,m=-1,off;
    for(int i=0;i<n;++i)
    {   int f=0;
        for(int j=i; j<n; ++j)
        {
            if(b[j]==0&&f==0)
            {
                c+=1;f=1; off=j;
            }
            if(b[j]==1)c+=1;
            else break;
        }
        if(c>m)
        {
            m=c;
            index=off;
        }
        c=0;
    }
    cout<<"Index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array is " <<index+1<<endl;
}
void Three_way_partitioning(int l,int r,int a[],int n)
{
    int sm[n],ra[n],la[n],x=0,y=0,z=0;
    for(int i=0;i<n;++i)
    {
       if(a[i]<l)sm[x++]=a[i];
       else if(a[i]>=l&&a[i]<=r)ra[y++]=a[i];
       else la[z++]=a[i];
    }
    cout<<"Array after sorting \n";
    for(int i=0;i<x;++i)cout<<sm[i]<<" ";
    for(int i=0;i<y;++i)cout<<ra[i]<<" ";
    for(int i=0;i<z;++i)cout<<la[i]<<" ";

}
void replace_equal(int arr[],int n)
{
    int b[N],i=0;
    for(int j=0;j<n;++j)
    {   arr[i++]=arr[j];
        while(i>1&&arr[i-1]==arr[i-2])
        {    i-=1;
            arr[i-1]+=1;
        }
    }
    cout<<"\nArray after replace two consecutive equal values\n";
    for(int j=0;j<i;++j)
        cout<<arr[j]<<" ";
}
int main()
{
    std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int a[N];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    Largest_Subarray(a,n);                                              //1
    cout<<"Maximum Product sub-array is "<<Max_Product(a,n)<<endl;      //2
    replace_greatest(a,n);                                              //3
    cout<<"Maximum circular sub-array sum "<<max_circule(a,n)<<endl;     //4
    Maximize(a,n);                                                      //5
    FIND_INDX(a,n);                                                     //6
     int l,r;
     cout<<"Enter the range plz";
     cin>>l>>r;
     Three_way_partitioning(l,r,a,n);                                    //7

                                                                         //8
                                                                         //9
     replace_equal(a,n);                                                 //10
}
