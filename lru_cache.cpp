class LRUCache {
private:
    int capacity;

    // {key, value}
    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};