//using bfs 
// first assign 0 to the cell with value 1 , and -1 to other cells
// then assign value 1 larger to the neibours layer by layer

#include <set>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector< vector<int> >& highestPeak( vector<vector<int>>& isWater) 
    {
        int numRows = isWater.size();
        int numCols = isWater[0].size();
        int numCells = numRows * numCols;
        
        set< pair<int, int> > visited;
        int numVisited = 0;
        queue< pair< pair<int, int>, int > > cell_value_queue;
        
        pair<int, int> pos;
        for ( int i = 0; i < numRows; ++i )
            for ( int j = 0; j < numCols; ++j )
            {
                if ( isWater[i][j] == 1 )
                {
                    isWater[i][j] = 0;
                    pos = make_pair( i, j );
                    visited.insert( pos );
                    ++numVisited;
                    cell_value_queue.push( make_pair( pos, 0 ) );
                }
                    
                else
                    isWater[i][j] = -1;            
            }
        
        int val, row, col;
        
        while ( numVisited < numCells && !cell_value_queue.empty() )
        {
            
            pos = cell_value_queue.front().first;
            val = cell_value_queue.front().second;
            
            row = pos.first;
            col = pos.second;
            
            pos = make_pair( row-1, col );
            if( row - 1 >= 0 && visited.find(pos) == visited.end() )
            {
                visited.insert( pos );
                numVisited++;
                isWater[row-1][col] = val + 1;
                cell_value_queue.push( make_pair( pos, val + 1 ) );
            }
            
            pos = make_pair( row+1, col );
            if( row + 1 < numRows && visited.find(pos) == visited.end() )
            {
                visited.insert( pos );
                numVisited++;
                isWater[row+1][col] = val + 1;
                cell_value_queue.push( make_pair( pos, val + 1 ) );
            }
            pos = make_pair( row, col-1 );
            if( col - 1 >= 0 && visited.find(pos) == visited.end() )
            {
                visited.insert( pos );
                numVisited++;
                isWater[row][col-1] = val + 1;
                cell_value_queue.push( make_pair( pos, val + 1 ) );
            }
            
            pos = make_pair( row, col+1 );
            if( col + 1 < numCols && visited.find(pos) == visited.end() )
            {
                visited.insert( pos );
                numVisited++;
                isWater[row][col+1] = val + 1;
                cell_value_queue.push( make_pair( pos, val + 1 ) );
            }
            
            cell_value_queue.pop();

        }
        
        return isWater;
    }
    
};

