#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    
    int val, size, swaps, theMax;    
    cin >> size >> swaps;    
    vector<int> vec;
     vector <int>::iterator pos = vec.begin ();
    
    for( int i=0 ; i < size ; i++){
        cin >> val;
        vec.push_back(val);
    }
    
    for( int i=0 ; i<swaps ; i++ ){
        theMax = *max_element(vec.begin(), vec.end());
        pos = find(vec.begin(),vec.end(), theMax) ;
        if(pos != vec.end()){
            iter_swap(vec.begin(), pos);
            cout << theMax << " ";
        }
        vec.erase(remove(vec.begin(), vec.end(), theMax), vec.end());        
    }   
    
    for(int i=0 ; i<vec.size() ; i++){
        cout << vec[i] << " ";
    }
    
    return 0;
}