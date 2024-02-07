class FreqStack {
private:
    int highestFrequency;
    unordered_map<int, int> counts;
    unordered_map<int, vector<int>> freqWiseElments;

public:
    FreqStack() {
        highestFrequency = 0;
    }
    
    void push(int val) {
        int updatedFrequency = ++counts[val];
        freqWiseElments[updatedFrequency].push_back(val);
        highestFrequency = max(highestFrequency, updatedFrequency);
    }
    
    int pop() {
        if(highestFrequency == 0)
            return -1;
        
        int poppedElement = freqWiseElments[highestFrequency].back();
        freqWiseElments[highestFrequency].pop_back();

        counts[poppedElement]--;
        if(freqWiseElments[highestFrequency].size() == 0)
            highestFrequency--;

        return poppedElement;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */