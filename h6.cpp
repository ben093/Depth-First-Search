#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct vertex{
	string color = "WHITE";
	int begin = 0;
	int end = 0;
	string parent = "";
};

unordered_map<string, vertex> key, key_T;
int time, time_T = 0;
vector<string> vect, vect_T;

void DFSVisit(unordered_map<string, vector<string>> G, string u)
{
	time++;
	key[u].begin = time;
	key[u].color = "GRAY";
	for(auto v: G[u])
		if(key[v].color == "WHITE")
		{
			key[v].parent = u;
			DFSVisit(G, v);
		}
	key[u].color = "BLACK";
	vect.push_back(u);
	time++;
	key[u].end = time;
	
}
void DFSVisit_T(unordered_map<string, vector<string>> G, string u)
{
	time_T++;
	key_T[u].begin = time_T;
	key_T[u].color = "GRAY";
	
	for(auto v: G[u])
		if(key_T[v].color == "WHITE")
		{
			key_T[v].parent = u;
			DFSVisit_T(G, v);
		}
	key_T[u].color = "BLACK";
	vect_T.push_back(u);
	time_T++;
	key_T[u].end = time_T;
}

void DFS(unordered_map<string, vector<string>> graph)
{
	for(auto x: graph)
	{
		for(auto y: x.second)
		{
			if(key[y].color == "WHITE")
			{
				DFSVisit(graph, x.first);
			}
		}
	}
}

void DFS_T(unordered_map<string, vector<string>> transpose)
{
	for(auto x: vect)
	{
		if(key_T[x].color == "WHITE")
		{
			DFSVisit_T(transpose, x);
		}
	}
}

void SinglyConnectedComponents(unordered_map<string, vector<string>> graph, unordered_map<string, vector<string>> transpose)
{
	DFS(graph);
	
	reverse(vect.begin(), vect.end()); //reverse vector to call on the transpose
	
	DFS_T(transpose);
	
	//OUTPUT
	vector<string> temp1, temp2;
	vector<vector<string>> result;
	for(auto x: vect_T)
	{
		if(key_T[x].parent != "")
		{
			temp1.push_back(x);
		}
		else
		{
			temp2.push_back(x);
			for(auto y: temp1)
			{
				temp2.push_back(y);
			}
			result.push_back(temp2);
			temp1.clear();
			temp2.clear();
		}
	}
	sort(result.begin(), result.end()); //sort result
	
	//print
	for(int i = 0; i < (int)result.size(); i++)
	{
		sort(result[i].begin(), result[i].end()); //sort result[i]
		
		for(auto x: result[i])
		{
			cout << x;
			if(x != result[i].back())
			{
				cout << " "; //only print space if not the last item
			}
		}
		cout << endl;
	}
}

int main()
{
	string vertexA, vertexB;
	
	unordered_map<string, vector<string>> graph, transpose;
	
	while(cin >> vertexA >> vertexB)
	{
		vertex original;
		if(graph.find(vertexA) == graph.end()) 
		{	//not in graph yet
			graph.emplace(vertexA, vect);
			key.emplace(vertexA, original);
			
			transpose.emplace(vertexA, vect);
			key_T.emplace(vertexA, original);
		}
		if(graph.find(vertexB) == graph.end()) 
		{	//not found in graph
			graph.emplace(vertexB, vect);
			key.emplace(vertexB, original);
			
			transpose.emplace(vertexB, vect);
			key_T.emplace(vertexB, original);
		}
		graph[vertexA].push_back(vertexB);
		transpose[vertexB].push_back(vertexA);
	}
	
	
	SinglyConnectedComponents(graph, transpose);
}
