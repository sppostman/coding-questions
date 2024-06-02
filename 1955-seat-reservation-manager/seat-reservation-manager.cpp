class MinHeap {
    vector<int> harr;

    public:
    MinHeap(){}

    MinHeap(int initRange){
        harr.resize(initRange);
        for(int i=1; i<=initRange; i++){
            harr[i-1] = i;
        }
    }

    int left(int i){
        return i*2;
    }
    int right(int i){
        return i*2 + 1;
    }
    int parent(int i){
        return i/2;
    }

    void insert(int key){
        harr.push_back(key);
        decreaseKey(harr.size()-1, key);
    }

    void decreaseKey(int idx, int newKey){
        harr[idx] = newKey;
        for(int i=idx; i>0 && harr[i] < harr[parent(i)]; i = parent(i))
            swap(harr[i], harr[parent(i)]);
    }

    int extractMin(){
        if(harr.size() == 0)
            return -1;
        int key = harr[0];

        harr[0] = harr[harr.size()-1];
        harr.pop_back();

        int i=0;
        while(i<harr.size()-1){
            int l = left(i);
            int r = right(i);

            int minChild = i;

            if(r < harr.size() && harr[r] < harr[minChild])
                minChild = r;
            if(l < harr.size() && harr[l] < harr[minChild])
                minChild = l;
        
            if(minChild == i)
                break;

            swap(harr[i], harr[minChild]);
            i = minChild;
        }

        return key;
    }
};

class SeatManager {
    MinHeap *heap;

public:
    SeatManager(int n) {
        heap = new MinHeap(n);
    }
    
    int reserve() {
        return heap->extractMin();
    }
    
    void unreserve(int seatNumber) {
        heap->insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */