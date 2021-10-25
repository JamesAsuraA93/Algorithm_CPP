//
//  main.cpp
//  Algorithm
//
//  Created by Peerapat Supasri on 25/10/2564 BE.
//

#include <iostream>
#include <list>

using namespace std;


int Bubble_sort(int Array_number[],long size){  // สร้างฟังก์ชัน Bubble_sort ขึ้นมาเพื่อเรียงลำดับ
    // Declare variable assign value of parameter
    long sub_rng = size;
    int temp; // use for swap value
    for(int i=0;i<size;i++){

        for(int j=0;j<sub_rng;j++){
            if(Array_number[j] > Array_number[j+1]){
                // if condition is true statement will be swap the value
                temp = Array_number[j];
                Array_number[j] = Array_number[j+1];
                Array_number[j+1] = temp;
            }
        }
        // decrease sub_rng for fix scope at the last number of array
        sub_rng--;
    }
    return Array_number[size-1]; // first that max value
}

class Graph  // Define class name Graph
{
    // assign attribute
    int V;
    list<int> *adj;
public: // Open type public of Attribute method
    Graph(int V){ // Initialize value in the class same like init.variable
        this->V = V; // Assign value V to this->V like a linked list
        adj = new list<int>[V]; // assign new list [V] to adj
    }
    void add(int v, int w){ // Define Method name add for add (tree) or arm of node เพิ่มแขนของกราฟ
        adj[v].push_back(w); // Assign v int the first and w in the back node
    }
    void BFS(int s); // Omitting method (#1)

};
 
 
void Graph::BFS(int s) // method by Omitting (#1)
{
    // Declare Variable to storage value new,parametor
    string temp = "";
    bool *visited = new bool[V];
    // assign value of array to false use for detect of visite node. If visited, will not storage in temp
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
    
    // visited make it true
    visited[s] = true;
    queue.push_back(s); // keep value in queue
    list<int>::iterator i; // use iterator of list value i
 
    while(!queue.empty())  // if queue not empty do statement
    {
        s = queue.front(); // assign value front of queue to s
        auto keep = to_string(s); // convert int s to keep that auto convert to string
        temp += keep + " "; // add more string(s) in temp and have space:char
        queue.pop_front(); // delete front of queue : done for detection
        for (i = adj[s].begin(); i != adj[s].end(); i++) // loop for start at begin and if non of end do statement
        {
            if (!visited[*i]) // if value address i doesn't visited od statement
            {
                visited[*i] = true; // assign that value is true
                queue.push_back(*i); // keep value in queue
            }
        }
    }
    // Declare variable use for convert string into array_num
    long size = temp.length();
    int array_num[size],cnt=0;
    for(int k=0;k<size;k++){ // use loop for
        if(temp[k] != ' '){ // if temp index k isn't space:char do statement
            int num = int(temp[k] - '0'); // convert string temp to int and assign with variable.num
            array_num[cnt] = num; // assign num on the array in index cnt
            cnt++; // plus more cnt for step the index
        }
    }
    
    // start Access value in Array and use bubble sort
    int Last_num = array_num[(size/2) - 1];
    int Max_BFS = Bubble_sort(array_num, size/2);
    // Compare with Max_BFS == Last_num condition and out put equal at Max_BFS if True and value Max_BFS and Last_num if False
    if(Max_BFS == Last_num){
        cout << "True it's Last num of BFS is equal Max number of node. num : " << Max_BFS << endl;
    }else{
        cout << "False it's not equal for Last num of BFS and Max number of node. Max num : " << Max_BFS << " and Last num : " << Last_num << endl;
    }
}

int main() {
    // สร้างมุมของกราฟไร้ลำดับทั้งหมด
    int edge = 5;
    Graph g(edge);
    
    // เพิ่มแขนของกราฟ ว่าแต่ละแขนมีอะไรบ้างต่อด้วยจุดไหนไปจุดไหน
    g.add(0,1);
    g.add(0,3);
    g.add(1,2);
    g.add(2,1);
    g.add(2,4);
    g.add(3,1);
    g.add(3,4);
    g.add(3,0);
    g.add(4,4);
    
    // start loop for detect BFS last node and loop with edge times
    for(int k=0;k<edge;k++){
        g.BFS(k); // use BFS method to Calculate BFS and Bubble sort in here
        cout << endl;
    }
    
    return 0;
}
