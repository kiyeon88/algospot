#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int> A, vector<int> B){
	return 0;
}
const long long NEGINF = numeric_limits<long long>::min();
int n, m;
vector<int> A, B;
int cache[101][101];
int jlis(int indexA, int indexB){
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < n; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	return ret;
}
int main(){
	int cases; cin >> cases;
	while (cases--){
		int lengthOfA, lengthOfB;
		cin >> lengthOfA >> lengthOfB;
		A.clear(); B.clear();
		A.resize(lengthOfA+1), B.resize(lengthOfB+1);
		A[0] = B[0] = -1;
		//vector<int> A(lengthOfA), B(lengthOfB);

		int count = 1;
		while (lengthOfA--)
			cin >> A[count++];
		count = 1;
		while (lengthOfB--)
			cin >> B[count++];
		
		memset(cache, -1, sizeof(cache));
		n = A.size(); m = B.size();
		cout<<jlis(0, 0)-2<<endl;
	}
}