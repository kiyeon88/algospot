#include<vector>
//#include<io.h>
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

bool myfunction(int i, int j){ return (i < j); }

std::vector<std::vector<int> > adj;
std::vector<bool> visited;

std::vector<int> seen, order; std::vector<bool> isUsed;
void dfs2(int here){
	seen[here] = 1; //isUsed[here] = false;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
		{
			dfs2(there); //isUsed[there] = true; 
		}
	//if (isUsed[here])
	order.push_back(here);

}

void makeGraph(const std::vector<std::string>& words){
	adj = std::vector<std::vector<int> >(26, std::vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j){
		int i = j - 1, len = std::min(words[i].size(), words[j].size());
		for (int k = 0; k < len; ++k)
			if (words[i][k] != words[j][k]){
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
	}
}

std::vector<int> topologicalSort(){
	int n = adj.size();
	seen = std::vector<int>(n, 0);
	isUsed = std::vector<bool>(n, false);
	order.clear();
	for (int i = 0; i < n; ++i)
		if (!seen[i]) dfs2(i);
	reverse(order.begin(), order.end());
	int m = order.size();
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j)
			if (adj[order[j]][order[i]])
				return std::vector<int>();
	return order;
}

int main()
{
	//initialization of cache array
	//memset(cache, -1, sizeof(cache));
	//printf("%d", fastSum(5));
	int cases;
	std::cin >> cases;
	while (cases--){
		int numofwords;
		std::cin >> numofwords;
		std::vector<std::string> words(numofwords);
		std::cin.ignore();
		while (numofwords--){
			std::getline(std::cin, words[words.size() - 1 - numofwords]);
		}
		makeGraph(words);
		std::vector<int> result, sortedResult; char print;
		result = topologicalSort();
		sortedResult.clear();
		sortedResult.assign(result.begin(), result.end());
		std::sort(sortedResult.begin(), sortedResult.end(), myfunction);
		if (result.size() == 0) std::cout << "INVALID HYPOTHESIS" << std::endl;
		else if (result == sortedResult){
			for (int i = 0; i < 26; ++i){
				print = i + 'a';
				std::cout << print;
			}
			std::cout << std::endl;
		}
		else {

			for (int i = 0; i < result.size(); ++i){
				print = result[i] + 'a';
				std::cout << print;
			}

			std::cout << std::endl;

		}


	}
	return 0;
}



