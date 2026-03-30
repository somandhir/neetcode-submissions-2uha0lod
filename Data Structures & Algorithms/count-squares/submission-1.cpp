class CountSquares {
public:
    map<pair<int,int>, int> freq;
    map<int, vector<int>> xMap; // x -> list of y

    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        freq[{x,y}]++;
        xMap[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        for(int y2 : xMap[x]) {
            if(y2 == y) continue;

            int d = y2 - y;

            // right side square
            res += freq[{x + d, y}] * freq[{x + d, y2}];

            // left side square
            res += freq[{x - d, y}] * freq[{x - d, y2}];
        }

        return res;
    }
};