#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int cache[100][100];
int solve(int row, int column, vector<vector<int> >& triangle){
	int& ret = cache[row][column];
	if (ret != -1) return ret;
	if (row == (triangle.size() - 1)) return ret=triangle[row][column];
	return ret = triangle[row][column] + max(solve(row + 1, column, triangle), solve(row + 1, column + 1, triangle));
	
}

int main(){
	int cases; cin >> cases;
	while (cases--){
		int sizeOfTriangle; cin >> sizeOfTriangle;
		vector<vector<int> > triangle(sizeOfTriangle);
		for (int i = 0; i < sizeOfTriangle; ++i){
			int input; 
			for (int j = 0; j <= i; ++j){
				cin >> input; triangle[i].push_back(input);
			}
				
		}
		memset(cache, -1, sizeof(cache));
		cout << solve(0, 0, triangle) << endl;
			

		
	}

}