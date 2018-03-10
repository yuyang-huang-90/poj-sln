#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#include<vector>
int temp[101],n;
int map[101][101];
// 求最大字段的和
int maxsub(int *arr,int n){
	int ans = arr[0];
	int maxend = arr[0];
	for (int i = 1; i < n; ++i) {
		if (maxend < 0) {
			maxend = arr[i];
		} else {
			maxend = arr[i] + maxend;
		}
		ans = max(ans, maxend);
	}
	return ans;
}

int main(){
    int N;cin>>N;
    int i,j,k;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)cin>>map[i][j];
    int maxAll=0,maxOne=0;
   //一二层的两个循环用来依次将一个二维图压缩成一维数列
    for(i=0;i<N;i++){//自上而下
        memset(temp,0,sizeof(temp));
        for(j=i;j<N;j++){//自上而下
            for(k=0;k<N;k++)temp[k]+=map[j][k];//自左到右
            maxOne=maxsub(temp,N);
            if(maxOne>maxAll)maxAll=maxOne;
        }
    }
    cout<<maxAll<<endl;
    return 0;
}

