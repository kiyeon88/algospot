#include<iostream>
#include<vector>

int cache[100][100];
int solveSubproblem(int numOfSquare, int first){
	
	if (numOfSquare==first) {
		return 1;
	}
	int& ret = cache[numOfSquare][first];
	if (ret != -1) return ret;
	else
	{
		for (int sencond = 1; sencond <= numOfSquare - first; ++sencond){
			if (cache[numOfSquare - first][sencond] == -1)
				cache[numOfSquare - first][sencond] = solveSubproblem(numOfSquare - first, sencond);
			ret += (cache[numOfSquare - first][sencond] * (sencond + first - 1));
		}
		return ret;
	}
	
	return ret;
}

int solve(int numOfSquare){
	int ret = 0;
	for (int i = 1; i <= numOfSquare; ++i)
		ret += solveSubproblem(numOfSquare, i);
	return ret;
}
using namespace std;
int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfSquare; cin >> numOfSquare;
		memset(cache, -1, sizeof(cache));
		cout << solve(numOfSquare) << endl;
	}
	return 0;
}