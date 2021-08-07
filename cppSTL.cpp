#include <bits/stdc++.h>


using namespace std;


//pair
void explainPair(){

	pair<int, int> p = {1, 3};

	//prints 1, 3

	cout << p.first << " " << p.second << endl;


	pair<int, pair<int, int>> d = {1, {3, 4}};

	//prints 1, 4, 3

	cout << d.first << " " << d.second.second << " " << d.second.first << endl;

	pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

	//prints 5
	cout << arr[1].second << endl;
}

//vector
void explainVector(){

	//An empty vector
	vector<int> v;

	v.push_back(1);
	v.emplace_back(2);
	
	for(int it : v) cout << it << " ";
	cout << endl;

	vector<pair<int , int>> vec;

	vec.push_back({1, 2}); //brackets are necessary

	vec.emplace_back(1,2); //brackets are danger

	for(int i = 0; i<vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}

	//vector of size 5
	//initialized with 0
	//might take garbage value
	//dependent on the vector

	vector<int> v2(5);

	//vector of size 5, initialized with 100

	vector<int> v3(5, 100); //100 100 100 100 100

	//vector copy during initialization
	vector<int> v4(v3); // 100 100 100 100 100

	vector<int> :: iterator it;

	cout << "V4 : " << endl;
	for(it = v4.begin(); it!=v4.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//v.end() points to after end
	//v.rend() points to before start
	//v.rbegin() points to end exact
	//v.back() last element

	v4.erase(v4.begin()); // first element

	// v4.erase(v4.begin() + 1); // erases 1 positions element

	// v4.erase(v4.begin() + 2, v4.begin() + 4); // start from 2 till 4 but not 4

	// v4.insert(v4.begin(), 23); // 23 . . 

	// v4.insert(v4.begin()+1, 2, 10); // 23 10 10 . . . . 

	// vector<int> copy(2, 50); // 50 50

	// v4.insert(v4.begin(), copy.begin(), copy.end()); // 50 50 23 10 10 . . . . 

	v4.clear(); // erases entire vector

	cout << v4.empty();

	//v1 -> (10, 20) , v2 -> (30 , 40)
	//v1.swap(v2); //v1 -> (30, 40), v2 -> (10, 20)


}

void explainList(){

	list<int> ls;

	ls.push_back(2); //{2}
	ls.emplace_back(4); // {4}

	ls.push_front(5); // {5, 2, 4}

	ls.emplace_front(3); // {3, 5, 2, 4}


}

void explainDeque(){

	deque<int> dq;
	dq.push_back(1); // 1
	dq.emplace_back(2); // {1, 2}
	dq.push_front(4); //{4, 1, 2}
	dq.emplace_front(3); // {3, 4, 1, 2}

	dq.pop_back(); // {3, 4, 1}
	dq.pop_front(); // {4, 1}

	dq.back();

	dq.front();

	//rest function same as vector

	//begin, end, rbegin, rend, clear, insert, size, swap

}

void explainStack(){

	stack<int> st;

	st.push(1); //{1}
	st.push(2); // {2, 1}
	st.push(3); // {3, 2, 1}
	st.emplace(5); //{5, 3, 3, 2, 1}

	cout << st.top() << endl; //prints 5 "st[2] is invalid"

	st.pop(); // {3, 3, 2, 1}

	cout << st.top() << endl; //{Prints 3}

	cout << st.size() << endl;

	cout << st.empty() << endl;

	stack<int> st1, st2;

	st1.swap(st2);

}

void explainQueue(){

	queue<int> q;
	q.push(1); // {1}
	q.push(2); // {1, 2}
	q.emplace(4); // {1, 2, 4}

	q.back() += 5;

	cout << q.back() << endl; // prints 9

	// Q is {1, 2, 9}
	cout << q.front() << endl; //prints 1

	q.pop(); //{2, 9}

	cout << q.front(); //prints 2

	//size swap empty same as stack
}

void explainPriorityQueue(){

	priority_queue<int> pq;

	pq.push(5); //{5}
	pq.push(2); //{5, 2}
	pq.push(8); //{8, 5 ,2}
	pq.emplace(10); // {10, 8, 5, 2}

	cout << pq.top(); // prints 10

	pq.pop(); //{8, 5, 2}

	cout << pq.top(); // prints 8

	//size swap empty function same as others

	//Minimum heap //greater int is a comparator that always stores in a reversable manner
	priority_queue<int , vector<int>, greater<int>> pq1;

	pq1.push(5); //{5}
	pq1.push(2); //{2, 5}
	pq1.push(8); //{2, 5, 8}
	pq1.emplace(10); //{2, 5, 8, 10}

	cout << pq1.top() << endl; // prints 2

}

//set stores elements in sorted order but only stores unique elements

void explainSet(){

	set<int> st;

	st.insert(1); //{1}
	st.insert(2); //{1, 2}
	st.insert(2); //{1, 2}
	st.insert(4); //{1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}
	st.insert(5); //{1, 2, 3, 4, 5}

	//functionality of insert in vector
	//can be used also, that only increases
	//efficiency

	//{1, 2, 3, 4, 5}

	auto it1 = st.find(3);

	auto it2 = st.find(6); //it will point to st.end()

	st.erase(5); // erases 5, takes logarithmic time

	auto it3 = st.find(3);

	st.erase(it3); //it takes constant time

	int cnt = st.count(1);

	st.insert(5);
	st.insert(6);

	//{1, 2, 4, 5, 6}
	auto it4 = st.find(2);
	auto it5 = st.find(5);
	st.erase(it4, it5); // after erase {1, 5, 6}

	auto it6 = st.lower_bound(2);

	auto it7 = st.upper_bound(3);  
}

//multiset is same as set but it allows you to store duplicates

void explainMultiSet(){

	multiset<int> ms;

	ms.insert(1); //{1}
	ms.insert(1); //{1, 1}
	ms.insert(1); //{1, 1, 1}

	ms.erase(1); //all 1's get erased

	//only a single one get erased
	ms.erase(ms.find(1));

	ms.erase(ms.find(1), ms.find(1)+2); //range

	//rest functions same as set

}


//unordered set takes unique elements but doesn't sort
void explainUSet(){

	unordered_set<int> st;

}

void explainMap(){

	//{key, value}
	map<int, int> mp;

	map<int, pair<int, int>> mpp;

	map<pair<int , int>, int> mp1;

	//key values can be anything

	mp[1] = 2;

	mpp.emplace({3, 1});

	mp1.insert[{2, 4}] = 10;

	/* {
		{1, 2}
		{2, 4}
		{3, 1}
	}*/

	for(auto it : mpp){
		cout << it.first << " " << it.second << endl;
	}

	cout << mp[1];

	auto it = mpp.find(3);
	cout << *(it).second << endl;

	auto it = mpp.lower_bound(2);

	auto it = mpp.upper_bound(3); 
}

//multimap stores multiple key those are simillar
void explainMultimap(){

	//mpp[key] can't be used here

}

void explainUnorderedMap(){
	//same as set and unordered_set difference
}

bool comp(pair<int, int> p1, pair<int , int> p2){

	if(p1.second < p2.second){
		return true;
	}
	else if(p1.second == p2.second){
		if(p1.first > p2.first) return true;
	}

	return false;
}

void explainExtra(){

	sort(a, a+n); //array sorts in ascending order

	sort(a+2, a+4); // first ,last

	sort(a, a+n, greater<int>); //descending order

	pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

	//sort it according to second element
	//if 2nd is matching sort descending
		
	sort(a, a+n, comp); //comparator function

	//{4, 1}, {2, 1}, {1, 2}

	int num = 7; //111

	int cnt = __builtin_popcount();

	ll num = 165786867;
	int cnt = __builtin_popcountll();

	string s = "123";

	do{
		cout << s << endl;
	}while(next_permutation(s.begin(), s.end()));

	//123 //dictionary order
	//132
	//213
	//231
	//312
	//321

	int maxi = *max_element(a, a+n);

}


int main(){


	//explainPair();

	//explainVector();

	//explainList();

	//explainDeque();

	//explainStack();

	// explainQueue();

	//explainPriorityQueue();

	//explainSet();

	//explainMultiSet();

	//explainUSet();

	//explainMap();

	return 0;
}
