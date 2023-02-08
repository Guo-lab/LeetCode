/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
    struct ListNode {
        int val, key;
        ListNode* next;
        ListNode* prev;
        ListNode() : val(-1), key(-1), next(nullptr), prev(nullptr) {} 
        ListNode(int val, int key, ListNode* next, ListNode* prev) : val(val), key(key), next(next), prev(prev) {} 
    };
    // -------------- Global --------------
    int MaxSize;
    unordered_map<int, ListNode*> cache;
    ListNode* dummyHead;
    ListNode* dummyTail;
    // ------------------------------------
    LRUCache(int capacity) {
        MaxSize = capacity;
        dummyHead = new ListNode();
        dummyTail = new ListNode();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if (cache.count(key) != 1) {
            return -1;   
        } else {
            ListNode* tmp = cache[key];
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;

            dummyHead->next->prev = tmp;
            tmp->next = dummyHead->next;
            dummyHead->next = tmp;
            tmp->prev = dummyHead; 
            return tmp->val;           
        }
    }

    void put(int key, int value) {
        if (cache.count(key) != 1) { // 反正是一定要放入的
            ListNode* tmp = new ListNode(value, key, nullptr, nullptr);

            dummyHead->next->prev = tmp;
            tmp->next = dummyHead->next;
            dummyHead->next = tmp;
            tmp->prev = dummyHead;

            cache[key] = tmp;
            MaxSize--;
            if (MaxSize < 0) {
                ListNode* del = dummyTail->prev;

                del->prev->next = del->next;
                del->next->prev = del->prev;
                cache.erase(del->key);

                MaxSize++; 
            }
        } else {
            ListNode *modify = cache[key];
            modify->val = value;
            modify->next->prev = modify->prev;
            modify->prev->next = modify->next;

            dummyHead->next->prev = modify;
            modify->next = dummyHead->next;
            dummyHead->next = modify;
            modify->prev = dummyHead;
        }
        ////printAll(dummyHead);     
    }

    void printAll(ListNode* pointer) {
        while (pointer != dummyTail) {
            cout << pointer->key << " " << pointer->val << endl;
            pointer = pointer->next;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


/**
 * @brief case
 * ["LRUCache","put","put","get","put","put","get"]\n[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]\n
 * answer:
 * [null,null,null,2,null,null,-1]
 * 
 * ["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]\n[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]\n
 * answer:
 * [null,null,null,null,null,4,3,2,-1,null,-1,2,3,-1,5]
 * 
 * 
 * Time Limit Exceeded with O_n_LRUCache
 * ["LRUCache","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put'... 3093237 more character
 * answer:
 * ...
 */


// unordered_map: 搜索时间复杂度 平均时间为 O(1)
// map          : 搜索时间复杂度 平均时间为 O(log n) 默认按照key从小到大进行排序

/**
 * @brief map_O(n)_get_&_put
 */
class O_n_LRUCache { // 别实现成 LFU, LRU: https://juejin.cn/post/7074754596480286734
public:
    map<int, int> cache; // https://blog.csdn.net/u011541946/article/details/107993270
    map<int, int> epoch;
    int CacheMax = 0;
    O_n_LRUCache(int capacity) {
        CacheMax = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            for (auto iter = epoch.begin(); iter != epoch.end(); iter++) {
                iter->second++;
            }
            epoch[key] = 0;
            return cache[key];            
        }
    }

    // Problem:  reference to non-static member function must be called
    // Solution: https://blog.csdn.net/weixin_40710708/article/details/111269356
    bool static cmp_value(const pair<int, int> left, const pair<int,int> right) {
	    return left.second < right.second;
    } /// https://blog.csdn.net/m0_50845934/article/details/116545628
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (CacheMax > 0) {
                for (auto iter = epoch.begin(); iter != epoch.end(); iter++) {
                    iter->second++;
                }
                cache.insert(make_pair(key, value));
                epoch.insert(make_pair(key, 0));
                CacheMax--;
            } else {
                auto maxPos = max_element(epoch.begin(), epoch.end(), cmp_value);
                auto minPos = max_element(epoch.begin(), epoch.end(), [](pair<int, int> left, pair<int,int> right) { return left.second >= right.second; });
                cache.erase(cache.find(maxPos->first));
                cache.insert(make_pair(key, value));
                epoch.erase(epoch.find(maxPos->first));
                epoch.insert(make_pair(key, 0));
                for (auto iter = epoch.begin(); iter != epoch.end(); iter++) {
                    iter->second++;
                }
                epoch[key]--;                
            }
        } else {
            cache[key] = value;
            for (auto iter = epoch.begin(); iter != epoch.end(); iter++) {
                iter->second++;
            }
            epoch[key] = 0;
        }
        
    }
};