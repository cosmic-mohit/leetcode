class MyHashMap {
public:
    vector<list<pair<int,int>>> v;
    int M;

    int getIdx(int key){
        return key%M;
    }

    MyHashMap() {
        M = 10000;
        v.resize(M);
    }
    
    void put(int key, int value) {
        int idx = getIdx(key);
        // auto itr = find(v[idx].begin(), v[idx].end(), key);

        for(auto &it : v[idx]){
            if(it.first == key){
                it.second = value;//update the existing key value pair
                return;
            }
        }
        // if new key value pair add it to the vector
        v[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = getIdx(key);
        
        for(auto &it : v[idx]){
            if(it.first == key){
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = getIdx(key);
       
       for(auto it = v[idx].begin(); it != v[idx].end(); it++){
            if(it->first == key){
                v[idx].erase(it);
                return;
            }
       }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */