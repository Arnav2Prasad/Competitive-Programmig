
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    std::vector<int> frequencies;
    for (auto& pair : taskCount) {
        frequencies.push_back(pair.second);
    }

    std::sort(frequencies.begin(), frequencies.end(), std::greater<int>());

    int maxFreq = frequencies[0];
    int idleSlots = (maxFreq - 1) * n;

    for (int i = 1; i < frequencies.size(); ++i) {
        idleSlots -= std::min(frequencies[i], maxFreq - 1);
    }

    return tasks.size() + std::max(0, idleSlots);
    }
};
