#include <bits/stdc++.h>
#define ll long long int
#define int long long int
using namespace std;

void build_segTree(vector<int>&seg_arr,vector<int>&arr,int l,int r,int ind,bool &f){
        if(l == r){
                f = 1;
                seg_arr[ind] = arr[l];
                return;
        }
        if( l > r ) return;
        int mid = l + (r-l)/2;
        build_segTree(seg_arr,arr,l,mid,ind*2+1,f);
        build_segTree(seg_arr,arr,mid+1,r,ind*2+2,f); 
        if(f){
                seg_arr[ind] = seg_arr[ind*2+1] | seg_arr[ind*2+2];
                f = 0;
        }
        else{
                seg_arr[ind] = seg_arr[ind*2+1] ^ seg_arr[ind*2+2];
                f = 1;
        }
}
void update_segTree(int p ,int b , vector<int>&seg_arr,int l,int r,int ind,bool &f){
        if( l > r) return ;
        if( p < l || p > r) return ;
        if(l == r){
                seg_arr[ind] = b;
                f = 1;
                return ;
        }
        int mid = l + (r - l)/2;
        if( p <= mid){
                update_segTree(p , b,seg_arr,l,mid,ind*2+1,f);
        }
        else{
                update_segTree(p , b,seg_arr,mid+1,r,ind*2+2,f);
        }
        if(f){
                seg_arr[ind] = seg_arr[ind*2+1] | seg_arr[ind*2+2];
                f = 0;
        }
        else{
                seg_arr[ind] = seg_arr[ind*2+1] ^ seg_arr[ind*2+2];
                f = 1;
        }
}
void mainSolve()
{
    int n ,q ;
    cin>>n>>q;
    int num = pow(2,n);
    vector<int>arr;
    vector<int>seg_arr(4*num);
    vector<pair<int,int>>que;
    for(int i = 0; i < num ; i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    for(int i = 0; i < q ; i++){
        int t,tt;
        cin>>t>>tt;
        que.push_back({t,tt});
    }
    bool f = 0;
    build_segTree(seg_arr,arr,0,num-1,0,f);
    // for(auto & x: seg_arr){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    for(auto &x:que){
        f = 0;
        update_segTree(x.first-1 , x.second ,seg_arr, 0 , num-1, 0,f);
        cout<<seg_arr[0]<<endl;
    }
}
 
int32_t main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        mainSolve();
    }
    return 0;
}
