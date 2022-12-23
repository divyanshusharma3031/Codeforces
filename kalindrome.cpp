#include<bits/stdc++.h>
using namespace std;

bool palindrome(int arr[],int n)
{
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(arr[i]!=arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool check(int arr[],int n,int x,bool &b)
{
    int i=0;
    int j=n-1;
    vector<int> aux;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            //pass
        }
        else
        {
            aux.push_back(arr[i]);
        }
    }
    i=0;
    j=aux.size()-1;
    while(i<=j)
    {
        if(aux[i]!=aux[j])
        {
            return false;
        }
        i++;
        j--;
    }
    b=true;
    return true;
}

void solve(int arr[],int n)
{
    if(palindrome(arr,n))
    {
        cout<<"YES\n";
        return;
    }
    if(n==2)
    {
        cout<<"YES\n";
        return;
    }
    int i=0;
    int j=n-1;
    bool b=true;
    while(i<=j)
    {
        if(arr[i]!=arr[j])
        {
            b=false;
            check(arr,n,arr[i],b);
            check(arr,n,arr[j],b);
            break;
        }
        i++;
        j--;
    }
    if(b)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}