#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100],n,i,l,r,mid,el;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>*(a+i);
	}
	cin>>el;
	l = 0,r = n-1,mid = n/2;
	if(*(a+l) == el)
	{
		cout<<"\n"<<l;
		return 1;
	}
	if(*(a+r) == el)
	{
		cout<<"\n"<<r;
		return 1;
	}
	if(*(a+r) < el || *(a+l) > el)
	{
		cout<<"\n-1";
		return 1;
	}
	while(l < r)
	{
		if(*(a+mid) < el)
		{
			l = mid;
			mid = (l+r)/2;
		}
		else if(*(a+mid) > el)
		{
			r = mid;
			mid = (l+r)/2;
		}
		else
		{
			cout<<"\n"<<mid;
			return 1;
		}
	}
	cout<<"\n-1";
	return 1;
}
