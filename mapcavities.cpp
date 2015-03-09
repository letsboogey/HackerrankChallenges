#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    int row, col, new_cell, map_size, current, next, prev, above, below;
    string line;

    //get map size from STDIN
    cin >> map_size ;

    //build map using 2D array
    int map[map_size][map_size];

    for(row = 0 ; row < map_size ; row++){
        cin >> line ;
        for(col = map_size-1 ; col > -1 ; col--){            
            new_cell = line[col] - '0';//convert character to int
            map[row][col] = new_cell;
        }
    }

    //print map
    for(row = 0 ; row <map_size ; row++){
        for(col = 0 ; col<map_size ; col++){
            //consider only non-border cells
            if((row > 0 && col > 0) && (row < map_size-1 && col < map_size-1)){
                current = map[row][col];
                next = map[row][col+1];
                prev = map[row][col-1];
                above = map[row-1][col];
                below = map[row+1][col];

                //print 'X' for cavities
                if(current>next && current>prev && current>above && current>below){
                   cout << 'X';
                   continue;
                }
            }
            cout << map[row][col];
        }
        cout << endl;
    }
    return 0;
}

