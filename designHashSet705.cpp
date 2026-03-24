class MyHashSet {
public:
    // now we will implement a hash fun to avoid using extra space

    int M; // total no. of bukets can go up to 10^4
    vector<list<int>> v;

    int getIdx(int key){
        return key%M;
    }

    MyHashSet() {
        M = 10000;
        // v.resize(15000);
        v = vector<list<pair<int,int>>(M);
    }
    
    void add(int key) {
        int idx = getIdx(key);
        
        for(auto &i : v[idx]){
            if(i.first == key){
                i.second
            }
        }
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        auto itr = find(v[idx].begin(),v[idx].end(), key);
        
        if(itr != v[idx].end()){
            v[idx].remove(key);
        }
    }
    
    bool contains(int key) {
        int idx = getIdx(key);
        auto itr = find(v[idx].begin(), v[idx].end(), key);

        return itr != v[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */