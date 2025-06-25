class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        if (num_counts.find(number) != num_counts.end()) {
            num_counts[number]++;
        } else {
            num_counts[number] = 1;
        }
    }
    
    bool find(int value) {
        for (const auto& entry : num_counts) {
            long long complement = (long long)value - entry.first;
            if (complement != entry.first) {
                if (num_counts.find(complement) != num_counts.end()) {
                    return true;
                }
            } else {
                if (entry.second > 1) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    unordered_map<long long, int> num_counts;
};