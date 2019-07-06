#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


//class LRUCache {
//private:
//	int n;
//	list<pair<int, int> > lis;
//	unordered_map<int, list<pair<int, int>>::iterator> m;
//public:
//	LRUCache(int capacity) {
//		n = capacity;
//	}
//
//	int get(int key) {
//		auto it = m.find(key);
//		int ans = -1;
//		if (it != m.end())
//		{
//			//移动到头部
//			ans = it->second->second;
//			lis.erase(it->second);
//			lis.push_front(make_pair(key, ans));
//			it->second = lis.begin();
//		}
//		return ans;
//	}
//
//	void put(int key, int value) {
//		auto it = m.find(key);
//		if (it != m.end())
//		{
//			//刚插入的也放在头部
//			lis.erase(it->second);
//			lis.push_front(make_pair(key, value));
//			m[key] = lis.begin();
//		}
//		else if (m.size() < n)
//		{
//			//头插
//			lis.push_front(make_pair(key, value));
//			m[key] = lis.begin();
//		}
//		else
//		{
//			//移除最后一个元素
//			auto it = lis.end();
//			it--;
//			m.erase(it->first);
//			lis.erase(it);
//			lis.push_front(make_pair(key, value));
//			it = lis.begin();
//			m[key] = it;
//		}
//	}
//};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		auto it = map.find(key);
//		if (it == map.end())
//			return -1;
//		ll.splice(ll.begin(), ll, it->second);
//		return it->second->second;
//	}
//
//	void put(int key, int value) {
//		auto it = map.find(key);
//		if (it != map.end())
//			ll.erase(it->second);
//		ll.push_front(make_pair(key, value));
//		if (map.size() > cap) {
//			int k = ll.rbegin()->first;
//			map.erase(k);
//		}
//	}
//
//private:
//	int cap;
//	list<pair<int, int>> ll;
//	unordered_map<int, list<pair<int, int> >::iterator> map;
//};


/*class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;
		l.splice(l.begin(), l, it->second);
		return it->second->second;
	}

	void set(int key, int value) {
		auto it = m.find(key);
		if (it != m.end()) l.erase(it->second);
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (m.size() > cap) {
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}

private:
	int cap;
	list<pair<int, int> > l;
	unordered_map<int, list<pair<int, int> >::iterator> m;
};*/