// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<numeric>
// #include<string.h>
// using namespace std;
// const int INF = 987654321;
// //int A[100];
// vector<int> A;
// 
// int getMinSqureError(int left, int right){
// 	if (right - left < 0) return INF;
// 	if (right - left == 0) return A[left] * A[left];
// 	float mean = 0.0;
// 	for (int i = left; i <= right; ++i)
// 		mean += (float)A[i];
// 	mean /= (float)(right - left + 1);
// 
// 	int roundingInteger = round(mean);
// 	int ret = 0;
// 	for (int i = left; i <= right; ++i){
// 		ret += (A[i] - roundingInteger) * (A[i] - roundingInteger);
// 	}
// 	return ret;
// }
// 
// 
// int cache[101][11];
// //vector<int> numOfQuantize;
// int solve(int left, int numOfInterval){
// 	int& ret = cache[left][numOfInterval];
// 	if (numOfInterval == 1) return ret = getMinSqureError(left, left);
// 	ret = solve(left, 1) + solve(left+1, numOfInterval - 1);
// 	for (int i = 1; i <= A.size() - left - numOfInterval; ++i)
// 		ret = min(ret, getMinSqureError(left, left + i) + solve(left + i + 1, numOfInterval-1));
// 	return ret;
// }
// 
// 
// int n;
// int B[101], pSum[101], pSqSum[101];
// void precalc(){
// 	sort(B, B + n);
// 	pSum[0] = B[0];
// 	pSqSum[0] = B[0] * B[0];
// 	for (int i = 1; i < n; ++i){
// 		pSum[i] = pSum[i - 1] + B[i];
// 		pSqSum[i] = pSqSum[i - 1] + B[i] * B[i];
// 	}
// }
// 
// int minError(int lo, int hi){
// 	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
// 	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
// 	int m = int(0.5 + (double)sum / (hi - lo + 1));
// 	int ret = sqSum - 2 * m*sum + m*m*(hi - lo + 1);
// 	return ret;
// }
// int quantize(int from, int parts){
// 	if (from == n) return 0;
// 	if (parts == 0) return INF;
// 	int& ret = cache[from][parts];
// 	if (ret != -1) return ret;
// 	ret = INF;
// 	for (int partSize = 1; from + partSize <= n; ++partSize)
// 		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
// 	return ret;
// }
// 
// 
// int main(){
// 	int cases; cin >> cases;
// 	while (cases--){
// 		int lengthOfSequence, numOfUse;
// 		cin >> lengthOfSequence >> numOfUse;
// 		int input, count = 0;
// 		A.resize(lengthOfSequence);
// 		//vector<int> sequence(lengthOfSequence);
// 		while (lengthOfSequence--){
// 			cin >> input; A[count++] = input;
// 		}
// 		n = count;
// 		memset(cache, -1, sizeof(cache));
//  		sort(A.begin(), A.end());
//  		//cout << solve(numOfUse, 0, A.size() - 1) << endl;
// 		cout << solve(0, numOfUse) << endl;
// 		//precalc();
// 		//cout << quantize(0, numOfUse)<<endl;
// 
// 	}
// 	return 0;
// }





#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>
using namespace std;

//int A[100];
vector<int> A;

int getMinSqureError(int left, int right){
	if (right - left < 0) return 500000;
	if (right - left == 0) return 0;
	float mean = 0.0;
	for (int i = left; i <= right; ++i)
		mean += (float)A[i];
	mean /= (float)(right - left + 1);

	int roundingInteger = round(mean);
	int ret = 0;
	for (int i = left; i <= right; ++i){
		ret += (A[i] - roundingInteger) * (A[i] - roundingInteger);
	}
	return ret;
}


int cache[100][100][10];
//vector<int> numOfQuantize;
int solve(int numOfInterval, int left, int right){
	int& ret = cache[left][right][numOfInterval];
	if (numOfInterval == 1) return ret = getMinSqureError(left, right);
	if (ret != -1) return ret;
	ret = solve(1, left, left) + solve(numOfInterval - 1, left + 1, right);
	for (int i = 1; i <= right - left - numOfInterval + 1; ++i)
		ret = min(ret, solve(1, left, left + i) + solve(numOfInterval - 1, left + i + 1, right));
	return ret;
}


int main(){
	int cases; cin >> cases;
	while (cases--){
		int lengthOfSequence, numOfUse;
		cin >> lengthOfSequence >> numOfUse;
		int input, count = 0;
		A.resize(lengthOfSequence);
		//vector<int> sequence(lengthOfSequence);
		while (lengthOfSequence--){
			cin >> input; A[count++] = input;
		}
		memset(cache, -1, sizeof(cache));
		sort(A.begin(), A.end());
		if (A.size() < numOfUse) numOfUse = A.size();
		cout << solve(numOfUse, 0, A.size() - 1) << endl;

	}
	return 0;
}














