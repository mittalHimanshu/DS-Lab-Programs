#include<iostream>
using namespace std;

class Matrix{
    
    private:
        int v;
        int **arr;
        
    public:
        Matrix(int v){
            
            this->v = v;
            arr = new int*[v];
            
            for(int i=0; i<v; i++){
                
                arr[i] = new int[v];
                for(int j=0; j<v; j++)
                    arr[i][j] = 0;
                
            }
            
        }
        
        void addEdge(int o, int d){
            
            if(o == v+1){
                
                v+=1;
                int **newArr;
                newArr = new int*[v];
                for(int i=0; i<v; i++)
                    newArr[i] = new int[v];
                copy(arr, arr+(v-1), newArr);
                arr = newArr;
            }
            
            arr[o-1][d-1] = 1;
        }
        
        void display(){
            
            for(int i=0; i<v; i++){
                
                for(int j=0; j<v; j++){
                    
                    cout<<arr[i][j]<<" ";
                    
                }
                cout<<endl;
                
            }
            
        }
    
};

int main(){
    
    int v, e;
    int origin, dest;
    cin >> v;
    Matrix obj(v);
    cin >> e;
    
    for(int i=0; i<e; i++){
        
        cin>>origin>>dest;
        obj.addEdge(origin, dest);
        
    }
    obj.display();
    
    cin>>e;
    for(int i=0; i<e; i++){
        cin>>origin>>dest;
        obj.addEdge(origin, dest);
    }
    obj.display();
    
}
