    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <unordered_set>
    #include <queue>
    
    using namespace std;
    
    
    unordered_map<string, vector<string>> graph;
    
    void dfs(string currentCity, unordered_set<string>& visited) {
        
        cout << currentCity << " ";
        visited.insert(currentCity);
        
        vector<string> neighbours = graph[currentCity];
        
        for(int i = 0; i < neighbours.size(); i++ ){
            string nextCity = neighbours[i];
            
            if(visited.count(nextCity) == 0) { // not visited
                dfs(nextCity, visited);
            }
        }
    }
    
    void bfs(const string& start){
        unordered_set<string> visited;
        queue<string> q;
        
        visited.insert(start);
        q.push(start);
        
        while(!q.empty()){
            string node = q.front();
            cout << node << " ";
            q.pop();
            
            for(string& n : graph[node]){
                if(visited.count(n) == 0){
                    visited.insert(n);
                    q.push(n);
                }
            }
        }
    }
    
    int main() {
        graph["mumbai"] = {"delhi", "hyderabad", "chennai" };
        graph["delhi"] = {"mumbai", "hyderabad", "kolkata" };
        graph["kolkata"] = {"delhi", "bangalore"};
        graph["hyderabad"] = {"mumbai", "delhi", "bangalore", "chennai" };
        graph["chennai"] = {"mumbai", "hyderabad", "bangalore" };
        graph["bangalore"] = {"chennai", "hyderabad", "kolkata" };
        
        unordered_set<string> visited;
        
        dfs("mumbai",visited);
        cout << endl;
        bfs("delhi");
        
        return 0;
    }
