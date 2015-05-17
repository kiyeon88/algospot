#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;
vector<int> makeBiggerSequence(int num, vector<int> elements, vector<int>& result){
	for (int i = 0; i < elements.size(); ++i)
	if (elements[i]>num) result.push_back(i);
	return result;
}

int solveLis(int start, vector<int>& elements){
	max(solveLis(start + 1, elements), 1 + solveLis(start + 1, makeBiggerSequence(elements[start], elements, elements) ));
}
int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfElements; cin >> numOfElements;
		vector<int> elements(numOfElements);
		int input;
		for (int i = 0; i < numOfElements; i++){
			cin >> input, elements[i] = input;
		}

	}
	return 0;
}