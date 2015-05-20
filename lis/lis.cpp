#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>


using namespace std;
// vector<int> makeBiggerSequence(int num, vector<int> elements, vector<int>& result){
// 	for (int i = 0; i < elements.size(); ++i)
// 	if (elements[i]>num) result.push_back(i);
// 	return result;
// }

// int solveLis(int start, vector<int>& elements){
// 	max(solveLis(start + 1, elements), 1 + solveLis(start + 1, makeBiggerSequence(elements[start], elements, elements) ));
// }

// int lis(const vector<int>& A){
// 	if (A.empty()) return 0;
// 	int ret = 0;
// 	for (int i = 0; i < A.size(); ++i){
// 		vector<int> B;
// 		for (int j = i + 1; j < A.size(); ++j)
// 		if (A[i] < A[j])
// 			B.push_back(A[j]);
// 		ret = max(ret, 1 + lis(B));
// 	}
// 	return ret;
// }

int n; int S[500];
int cache[500]; 
//vector<int> S;
int lis2(int start){
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next)
	if (S[start] < S[next])
		ret = max(ret, lis2(next) + 1);
	return ret;
}

// int lis3(int start){
// 	int& ret = cache[start + 1];
// 	if (ret != -1) return ret;
// 	ret = 1;
// 	for (int next = start + 1; next < n; ++next)
// 	if (start == -1 || S[start] < S[next])
// 		ret = max(ret, lis3(next) + 1);
// 	return ret;
// }

int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfElements; cin >> numOfElements;
		//vector<int> elements(numOfElements);
		int input;
		memset(S, -1, sizeof(S));
		for (int i = 0; i < numOfElements; i++){
			cin >> input; 
			//elements[i] = input; 
			S[i] = input;
		}
		n = numOfElements;
		//cout << lis(elements) << endl;
		memset(cache, -1, sizeof(cache));
		if (n != 0){
			int maxLen = 0;
			for (int begin = 0; begin < n; ++begin)
				maxLen = max(maxLen, lis2(begin));
			cout << maxLen << endl;
		}
		else
			cout << 0 << endl;
		

	}
	return 0;
}