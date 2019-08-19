//https://leetcode.com/discuss/interview-question/347457

struct QNode{
    pair<int, int> posn;
    int dist;
    QNode(int x, int y, int d){  
        posn = pair<int, int>(x, y);
        dist = d;
    }
};

bool isSafe(vector<vector<char>> island, int row, int col){
    if(row >= 0 && row < island.size() && col >= 0 && col < island[0].size() && island[row][col] != 'D'){
        return true;
    }
    return false;
}

int treasureIsland(vector<vector<char>> island){
    int rows = island.size();
    int cols = island[0].size();
    queue<QNode> q;
    q.push(QNode(0,0,0));
    while(!q.empty()){
        QNode cur = q.front();
        int cur_x = cur.posn.first; int cur_y = cur.posn.second;
        if(island[cur_x][cur_y] == 'X') return cur.dist;
        //visit the node
        island[cur_x][cur_y] = 'D';
        q.pop();
        int left = cur_y - 1; int right = cur_y + 1;
        int up = cur_x - 1; int down = cur_x + 1;
        if(isSafe(island, up, cur_y)){
            q.push(QNode(up, cur_y, cur.dist+1));
        }
        if(isSafe(island, down, cur_y)){
            q.push(QNode(down, cur_y, cur.dist+1));
        }
        if(isSafe(island, cur_x, left)){
            q.push(QNode(cur_x, left, cur.dist+1));
        }
        if(isSafe(island, cur_x, right)){
            q.push(QNode(cur_x, right, cur.dist+1));
        }
    }
    return -1;
}


int main() {
    vector<vector<char>> g ={
        {'O', 'O', 'O', 'O'},
        {'D', 'O', 'D', 'O'},
        {'O', 'O', 'O', 'O'},
        {'X', 'D', 'D', 'O'}
    };
   cout << treasureIsland(g) << endl;
}
