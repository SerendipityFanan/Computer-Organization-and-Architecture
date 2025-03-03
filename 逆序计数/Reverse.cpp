#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int merge(vector<int>& nums,int left,int mid,int right,vector<pair<int,int>>& inversions) 
{
    int count=0;
    int i=left,j=mid+1;
    vector<int> temp;
    while(i<=mid&&j<=right) 
	{
        if(nums[i]<=nums[j]) 
		{
            temp.push_back(nums[i++]);
        } 
		else 
		{
            for(int k=i;k<=mid;++k) 
			{
                inversions.push_back(make_pair(nums[k],nums[j]));
            }
            count+=(mid-i+1); 
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid) 
	{
        temp.push_back(nums[i++]);
    }
    while(j<=right) 
	{
        temp.push_back(nums[j++]);
    }
    for(int k=left;k<=right;++k) 
	{
        nums[k]=temp[k-left];
    }
    return count;
}
int mergeSort(vector<int>& nums,int left,int right,vector<pair<int,int>>& inversions) 
{
    if(left>=right) return 0;
    int mid=left+(right-left)/2;
    int count=0;
    count+=mergeSort(nums,left,mid,inversions);
    count+=mergeSort(nums,mid+1,right,inversions);
    count+=merge(nums,left,mid,right,inversions);
    return count;
}
int main() 
{
    cout << "请输入个数 N 和数字序列：" << endl;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i) 
	{
        cin>>nums[i];
    }
    vector<pair<int,int>> inversions;
    int count=mergeSort(nums,0,n-1,inversions);
    cout <<endl<<"逆序对的个数和逆序对：" << endl;
    cout<<count<<endl;
    for(const auto& inv:inversions) 
	{
        cout<<inv.first<<"-"<<inv.second<<endl;
    }

    system("pause");
    return 0;
}
