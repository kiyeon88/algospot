#include<iostream>
#include<vector>
#include<map>



using namespace std;

int solve(map<int, int>& nerds, int x, int y){
	if (nerds.empty()) {
		nerds.insert(make_pair(x, y)); return 1;
	}
	
	map<int, int>::iterator iter, iter2, it;
	iter = nerds.upper_bound(x); iter2 = nerds.lower_bound(x);
	if (iter == nerds.begin() && y < iter->second) nerds.erase(iter->first);
	else if (iter == nerds.begin() && y >= iter->second) nerds.insert(make_pair(x, y));
	else if (x > (nerds.rbegin())->first){
		it = nerds.begin();
		while (it != nerds.end()){
			if (it->second < y) {
				it = nerds.erase(it); nerds.insert(make_pair(x, y));
			}			
			else 
				nerds.insert(make_pair(x, y)); ++it;
			
		}
		
		
	}
	else{
		iter2 = nerds.lower_bound(x);
		it = nerds.begin();
		while (it != nerds.end()){
			if (it->first < iter2->first && it->second < y) { it = nerds.erase(it); nerds.insert(make_pair(x, y)); }
			else if (it->first >iter2->first&&it->second > y) ++it;
			else {
				nerds.insert(make_pair(x, y)); ++it;
			}
		}		
		
	}
	return nerds.size();
	
}
int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfPeople; cin >> numOfPeople;
		vector<int> p(numOfPeople), q(numOfPeople); map<int, int> nerds;
		int x, y, ret=0;
		//int count = 0;
		while (numOfPeople--){
			cin >> x >> y;
			ret+=solve(nerds, x, y);
			//count++;

		}
		cout << ret << endl;
	}
}