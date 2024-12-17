// Dijikstra's Algorithm
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unistd.h>
using namespace std;

unordered_map<char,vector<pair<char,int>>> graph; //startnode endnode weight
vector<char> cities = {'A','B','C','D'}; 

string getColor(char city){
	switch(city){
		case 'A' : return "\033[31m";
		case 'B' : return "\033[32m";
		case 'C' : return "\033[33m";
		case 'D' : return "\033[34m";
		default : return "\033[0m";
	}
	return "\033[0m";
}

void dijikstra(char start){
	unordered_map<char,int> dist;
	unordered_map<char,char> parent;
	priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
	
	for(auto& city : cities){
		dist[city] = INT_MAX;
	}
	dist[start] = 0;
	pq.push({0,start});
	
	while(!pq.empty()){
		auto& pair = pq.top();
		int weight = pair.first;
		char vertex = pair.second;
		pq.pop();

		for(auto& neighbor : graph[vertex]){
			char nextCity = neighbor.first;
			int nextdist = neighbor.second;

			if(dist[vertex]+nextdist<dist[nextCity]){
				dist[nextCity] = dist[vertex] + nextdist;
				pq.push({dist[nextCity],nextCity});
				parent[nextCity] = vertex;
			}
		}
		
	}

	cout << "Node\t Distance from " << getColor(start)<< start <<"\033[0m" << endl;
	for(auto& city : cities){
		cout << getColor(city) << city << "\033[0m \t" << (dist[city] == INT_MAX ? -1 : dist[city])<<endl;
	}

	cout << "\n Shortest Paths : \n";
	for(auto& city : cities){
		if(city==start || dist[city] == INT_MAX) continue;
		cout << getColor(city) << city << "\033[0m <- ";
		char curr = city;
		while(parent.find(curr) != parent.end()){
			curr = parent[curr];
			cout << getColor(curr) << curr << "\033[0m" ;
			if(curr != start) cout << " <- ";
		}
		cout << endl;
	}
}


void display(){
	cout << "Displaying graph...." <<endl;
	sleep(1);
	for(auto& node : cities){
		cout << getColor(node) << node << "\033[0m -> "  ;
		if(graph.find(node) != graph.end()){
			for(auto& connected : graph[node]){
				cout << " ( " << getColor(connected.first) << connected.first << "\033[0m , " << connected.second << " ) ";
			}
		}else{
			cout << " () " ;
		}
		cout << endl;
	}
	sleep(1);
	cout << "Graph displayed successfully ! " <<endl;
	
}

int main(){
	graph['A'] = {{'B',1},{'C',4}};
	graph['B'] = {{'C',2},{'D',6}};
	graph['C'] = {{'D',3}};
	display();
	dijikstra('A');
	return 0;
}