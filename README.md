# Hackerrank Challenges

### 1. Cavity Map

[Problem statement](https://www.hackerrank.com/challenges/cavity-map "cavity-map")

Code below shows my first attempt at the problem and it did not pass all the test cases. Here's why:

The input I got from stdin was an integer 'I' which had 'N' digits with each digit representing a cell in the map, and the integer 'I' was an entire row in the map grid. This initial approach passed the test cases where 'I' was within the max range of int in c++ which is -2,147,483,647 to 2,147,483,647. For inputs outside this range like    'int I = 9999999999' it would fail to create the map as intended and hence fail the test case. 


```
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    //variable declaration
    int row, col, row_line, new_cell, current, next, prev, above, below, map_size;

    //get map size from STDIN
    cin >> map_size ;

    //fill 2-D array with cell values
    int map[map_size][map_size];
    for(row = 0 ; row < map_size ; row++){
        cin >> row_line ;//get current row
        for(col = map_size-1 ; col > -1 ; col--){

            new_cell = row_line%10;//get last digit in row_line
            row_line /= 10;//remove last digit in row_line

            //insert value
            map[row][col] = new_cell;
        }
    }

    for(row = 0 ; row <map_size ; row++){
        for(col = 0 ; col<map_size ; col++){
            //consider only non-border cells
            if((row > 0 && col > 0) && (row < map_size-1 && col < map_size-1)){
                current = map[row][col];
                next = map[row][col+1];
                prev = map[row][col-1];
                above = map[row-1][col];
                below = map[row+1][col];

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

```
I fixed this problem by receiving the input as a string instead and then simply converting each character into an int before adding it to the grid.
