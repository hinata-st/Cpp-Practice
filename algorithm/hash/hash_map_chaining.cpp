#include <bits/stdc++.h>

using namespace std;

/*键值对*/
struct  Pair
{
    public:
        int key;
        string val;
        Pair(int key,string val)
        {
            this->key = key;
            this->val = val;
        }
};


/*链式地址哈希表*/
class HashMapChaining
{
    private:    
        int size;                           //键值对数量
        int capacity;                       //哈希表容量
        double loadThres;                   //触发扩容的负载因子阈值
        int extendRatio;                    //扩容倍数
        vector<vector<Pair *>> buckets;    //桶数组

    public:
        /* 构造方法 */
        HashMapChaining():size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2)
        {
            buckets.resize(capacity); // 设置桶的数量下限，让容器提前分配足够的内存
        }
        /*析构方法*/
        ~HashMapChaining()
        {
            for (auto &bucket : buckets)
            {
                for (Pair *pair : bucket)
                {
                    delete pair;
                }
            }
        }

        /*哈希函数*/
        int hashFunc(int key)
        {
            return key % capacity;
        }

        size_t myHashFunc(int key)
        {
            return (hash<int>()(key)) % capacity;
        }

        /* 负载因子*/
        double loadFactor()
        {
            return (double)size / (double)capacity;
        }

        /* 查询操作*/
        string get(int key)
        {
            //int index = hashFunc(key);
            int index = myHashFunc(key);
            //遍历桶,若找到key,则返回对应val
            for (Pair *pair : buckets[index])
            {
                if(pair->key == key)
                {
                    return pair->val;
                }
            }
            //如未找到key,则返回空字符串
            return " ";
        }

        void put(int key,string val)
        {
            //当负载因子超过阈值时，执行扩容
            if (loadFactor() > loadThres)
            {
                extend();
            }
            //int index = hashFunc(key);
            int index = myHashFunc(key);
            // 遍历桶，若遇到指定key,则更新对应val并返回
            for (Pair *pair : buckets[index])
            {
                if(pair->key == key)
                {
                    pair->val = val;
                    return;
                }
            }
            //若无该key,则将键值对添加至尾部
            buckets[index].push_back(new Pair(key, val));
            size++;
        }


        void remove(int key)
        {
            //int index = hashFunc(key);
            int index = myHashFunc(key);
            auto &bucket = buckets[index];
            for (int i = 0; i < bucket.size();i++)
            {
                if(bucket[i]->key == key)
                {
                    Pair *tmp = bucket[i];              //从中删除键值对
                    bucket.erase(bucket.begin() + i);   //释放内存
                    delete tmp;
                    size--;
                    return;
                }
            }
        }
        void extend()
        {
            //暂存原哈希表
            vector<vector<Pair *>> bucketsTmp = buckets;
            //初始化扩容后的新哈希表
            capacity *= extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;
            //将键值对从哈希表搬运至新哈希表
            for(auto &bucket : bucketsTmp)
            {
                for(Pair *pair : bucket)
                {
                    put(pair->key, pair->val);
                    //释放内存
                    delete pair;
                }
            }
        }

        void print()
        {
            for(auto &bucket : buckets)
            {
                cout << "[";
                for(Pair *pair : bucket)
                {
                    cout << pair->key << " -> " << pair->val << ", ";
                }
                cout << "]\n";
            }
        }
};

int main()
{
    HashMapChaining map = HashMapChaining();
    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map.put(12836, "小哈");
    map.put(15937, "小啰");
    map.put(16750, "小算");
    map.put(13276, "小法");
    map.put(10583, "小鸭");
    cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
    map.print();

    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    string name = map.get(13276);
    cout << "\n输入学号 13276 ，查询到姓名 " << name << endl;

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.remove(12836);
    cout << "\n删除 12836 后，哈希表为\nKey -> Value" << endl;
    map.print();

    return 0;
}