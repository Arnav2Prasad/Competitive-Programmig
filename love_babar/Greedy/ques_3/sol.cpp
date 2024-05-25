
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
       if (x + y < target) {
            return false; // if the sum of both jugs is less than the target, it's impossible
        }

        // If the target is zero or equal to the sum of both jugs
        if (target == 0 || target == x + y) {
            return true;
        }

        // Use BFS to explore all possible states
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [curr_x, curr_y] = q.front();
            q.pop();

            // If the current state matches the target, return true
            if (curr_x == target || curr_y == target || curr_x + curr_y == target) {
                return true;
            }

            // All possible next states
            vector<pair<int, int>> next_states = {
                {x, curr_y}, // fill x jug
                {curr_x, y}, // fill y jug
                {0, curr_y}, // empty x jug
                {curr_x, 0}, // empty y jug
                {curr_x - min(curr_x, y - curr_y), curr_y + min(curr_x, y - curr_y)}, // pour x to y
                {curr_x + min(curr_y, x - curr_x), curr_y - min(curr_y, x - curr_x)}  // pour y to x
            };

            for (auto& state : next_states) {
                if (visited.find(state) == visited.end()) {
                    q.push(state);
                    visited.insert(state);
                }
            }
        }

        return false; // if all possible states are explored and none matches the target




    }
};
