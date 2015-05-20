#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

short cache1[10000];
short cache[10000][10000];
vector<short> A;
//int A[10000];
short solve(int left, int right){
	short& ret = cache[left][right];
	if (ret != -1) return ret;
	//ret = 0;
	if ((right - left) < 2) return 20;
	else if ((right - left) == 2){
		short difference[2]; 
		for (int i = 0; i < 2; ++i)
			difference[i] = A[left + i + 1] - A[left + i];
		if (difference[0]==0 && difference[1]==0) return ret=1;
		else if ((difference[0] * difference[1]) == 1) return ret = 2;
		else if (difference[0] == (difference[1] * (-1))) return ret = 4;
		else if (difference[0] == difference[1]) return ret = 5;
		else return ret = 10;
	}
	else if ((right - left) == 3){
		short difference[3];
		for (int i = 0; i < 3; ++i)
			difference[i] = A[left + i + 1] - A[left + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0) return ret = 1;
		else if (abs(difference[0] * difference[1] * difference[2]) == 1 && difference[0] == difference[1] && difference[1] == difference[2]) return ret = 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1))) return ret = 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2]) return ret = 5;
		else return ret = 10;

	}
	else if ((right - left) == 4){
		short difference[4];
		for (int i = 0; i < 4; ++i)
			difference[i] = A[left + i + 1] - A[left + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0 && difference[3] == 0) return ret = 1;
		else if (abs(difference[0] * difference[1] * difference[2] * difference[3]) == 1 && difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return ret = 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1)) && difference[2] == (difference[3] * (-1))) return ret = 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return ret = 5;
		else return ret = 10;
	}

	ret = solve(left, left + 2) + solve(left + 3, right);
	for (int i = 3; i < 5; ++i)
		ret = (short)min((int)ret, solve(left, left + i) + solve(left + i + 1, right));
	return ret;	
}

short getScore(int pos, int num){
	if (num == 3){
		short difference[2];
		for (int i = 0; i < 2; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0) return 1;
		else if ((difference[0] * difference[1]) == 1) return 2;
		else if (difference[0] == (difference[1] * (-1))) return 4;
		else if (difference[0] == difference[1]) return 5;
		else return 10;
	}
	else if (num == 4){
		short difference[3];
		for (int i = 0; i < 3; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0) return 1;
		else if (abs(difference[0] * difference[1] * difference[2]) == 1 && difference[0] == difference[1] && difference[1] == difference[2]) return 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1))) return 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2]) return 5;
		else return 10;
	}
	else if (num == 5){
		short difference[4];
		for (int i = 0; i < 4; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0 && difference[3] == 0) return 1;
		else if (abs(difference[0] * difference[1] * difference[2] * difference[3]) == 1 && difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1)) && difference[2] == (difference[3] * (-1))) return 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return 5;
		else return 10;
	}
}

short solve1(int pos){
	short& ret = cache1[pos];
	if (ret != -1) return ret;
	//ret = 0;
	
	
	
	if ((A.size() - 1 - pos) < 2) return 20;
	else if ((A.size() - 1 - pos) == 2){
		short difference[2];
		for (int i = 0; i < 2; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0) return ret = 1;
		else if ((difference[0] * difference[1]) == 1) return ret = 2;
		else if (difference[0] == (difference[1] * (-1))) return ret = 4;
		else if (difference[0] == difference[1]) return ret = 5;
		else return ret = 10;
	}
	else if ((A.size() - 1 - pos) == 3){
		short difference[3];
		for (int i = 0; i < 3; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0) return ret = 1;
		else if (abs(difference[0] * difference[1] * difference[2]) == 1 && difference[0] == difference[1] && difference[1] == difference[2]) return ret = 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1))) return ret = 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2]) return ret = 5;
		else return ret = 10;

	}
	else if ((A.size() - 1 - pos) == 4){
		short difference[4];
		for (int i = 0; i < 4; ++i)
			difference[i] = A[pos + i + 1] - A[pos + i];
		if (difference[0] == 0 && difference[1] == 0 && difference[2] == 0 && difference[3] == 0) return ret = 1;
		else if (abs(difference[0] * difference[1] * difference[2] * difference[3]) == 1 && difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return ret = 2;
		else if (difference[0] == (difference[1] * (-1)) && difference[1] == (difference[2] * (-1)) && difference[2] == (difference[3] * (-1))) return ret = 4;
		else if (difference[0] == difference[1] && difference[1] == difference[2] && difference[2] == difference[3]) return ret = 5;
		else return ret = 10;
	}

	ret = getScore(pos, 3) + solve1(pos + 3);
	for (int i = 3; i < 5; ++i)
		ret = (short)min((int)ret, getScore(pos, i+1) + solve1(pos + i + 1));
	return ret;





}

const int INF = 987654321;
string N;
int classify(int a, int b){
	string M = N.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])) return 1;
	bool progressive = true;
	for (int i = 0; i < M.size()-1; ++i)
	if (M[i + 1] - M[i] != M[1] - M[0])
		progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
	if (M[i] != M[i % 2])
		alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;

}
int cache3[10002];
int memorize(int begin){
	if (begin == N.size()) return 0;
	int& ret = cache3[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int L = 3; L <= 5; ++L)
	if (begin + L <= N.size())
		ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
	return ret;
}
int  main(){
	int cases; cin >> cases;
	while (cases--){
		//string input; cin >> input;
		cin >> N;
		//vector<int> numbers(input.size());
// 		A.resize(input.size());
// 		for (int i = 0; i < A.size(); ++i)
// 			A[i] = input[i]-48;
		//memset(cache, -1, sizeof(cache));
		//memset(cache1, -1, sizeof(cache1));
		memset(cache3, -1, sizeof(cache3));
		//cout<<solve1(0)<<endl;
		cout << memorize(0) << endl;
	}
}