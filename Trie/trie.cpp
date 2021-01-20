#include<bits/stdc++.h>
using namespace std;


//트라이의 정점노드
class TrieNode {
	public :
		bool valid;  //그 정점이 실제 존재하는지 , 없는 노드인데 지나가는 정점인지
		int child[26]; //정점 이후에 자식들
		TrieNode() { //생성자

			valid = false; //  정점은 일단 존재하지 않다.

			//초기화
			for (int i = 0; i < 26; i++) child[i] = -1; 

		}
};

//전체 트리구조
class Trie {

	private:
		vector<TrieNode> trie; //노드로 이루어진 벡터를 생성

		int _newNode() {
			TrieNode tmp; //정점을 하나 만든다. 
			trie.push_back(tmp); //현재 트리에 하나 넣는다

			return trie.size() - 1; //??
		}

		void _add(string& str, int node, int idx) {

			if (idx == str.size()) { //다 생성했다면~
				trie[node].valid = true; 
				return;
			}

			int c = str[idx] - 'A'; // 어떤문자냐?

				if (trie[node].child[c] == -1) {
					int next = _newNode();
					trie[node].child[c] = next;
				}
				_add(str, trie[node].child[c], idx + 1);
		}

		bool _exist(string& str) {

			int now = 0;

			for (int i = 0; i < str.size(); i++) {
				int c = str[i] - 'A';

				if (trie[now].child[c] == -1) return false;

				now = trie[now].child[c];
			}

			return trie[now].valid;
		}


	public:

		Trie() {
			_newNode();
		}
		void add(const char str[]) {
			string tmp(str);
			_add(tmp, 0, 0);
		}

		void add(string& str) {
			_add(str, 0, 0);
		}
		bool exist(string& str) {
			return _exist(str);
		}
		bool exist(const char str[]) {
			string tmp(str);
			return _exist(tmp);
		}
};

int main() {
	Trie a;
	a.add("ASDF");
	a.add("FDSA");
	a.add("NJH");
	a.add("NJHAF");
	printf("%d\n", a.exist("ASDF"));
	printf("%d\n", a.exist("ASD"));
	printf("%d\n", a.exist(""));
	printf("%d\n", a.exist("NJ"));
	printf("%d\n", a.exist("NJH"));
	printf("%d\n", a.exist("NJHA"));
	printf("%d\n", a.exist("NJHAF"));
	printf("%d\n", a.exist("NJHAD"));
}