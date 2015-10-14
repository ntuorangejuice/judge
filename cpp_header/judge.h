#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void SHOWANY(vector<string> name, T t) {
    cout << name.front() << " = " << t << endl;
}
template<typename T, typename... Args>
void SHOWANY(vector<string> name, T t, Args... args) {
    cout << name.front() << " = " << t << ", ";
    name.erase(name.begin());
    SHOWANY(name, args...);
}

vector<string> split_name(string name) {
	// does not support string ""
	vector<string> n;
	bool following_comma = false;
	int bracket = 0;
	int l = 0;
	int r = 0;
	for ( ; r < name.length(); r++) {
		char cur = name[r];
		if (cur == '(')
			bracket++;
		if (cur == ')')
			bracket--;
		if (bracket)
			continue;
		if (cur == ',') {
			n.push_back(name.substr(l, r - l));
			l = r + 1;
			following_comma = true;
		}
		else if (cur == ' ' && following_comma)
			l = r + 1;
		else
			following_comma = false;
	}
	n.push_back(name.substr(l, r - l));
	return n;
}

#ifdef SHOW
#undef SHOW
#endif
#ifdef REACH_HERE
#undef REACH_HERE
#endif
#define SHOW(...) { cout << __LINE__ << ": " ; SHOWANY(split_name(#__VA_ARGS__), __VA_ARGS__); }
#define REACH_HERE { cout << __LINE__ << ": REACH_HERE!" << endl; }