#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vt vector
// this infers the type of x and loops through.
#define EACH(x, a) for (auto& x: a)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// TO STRING TEMPLATES
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}

template<class T> string to_string(T v) {
	bool f=1;
	string res;
	EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
	return res;
}

template<class T, size_t S> string to_string(ar<T, S> x) {
	string res;
	for (auto i: x) {
		res += to_string(i);
	}
	return res;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

void solve() {
	int n;
	read(n);

	vector<vector<int>> v(n, vector<int>(2));
	read(v);
	
	unordered_map<int, vector<int>> mx;
	unordered_map<int, vector<int>> my;
	
	for (vector<int> vt : v) {
		mx[vt[0]].push_back(vt[1]);
		my[vt[1]].push_back(vt[0]);
	}
	//sort

	for(auto& it : mx) {
		sort(it.second.begin(), it.second.end());
	}

	for(auto& it : my) {
		sort(it.second.begin(), it.second.end());
	}

	int res = 0;

	for (auto& it : mx) {
		if (it.second.size() <= 2) {
			continue;
		} else {
			for (int i = 1; i < it.second.size() - 1; i++) {
				vector<int> arr = my[it.second[i]];
				int l = 0;
				int r = arr.size() - 1;
				int mid;
				while (l <= r) {
					mid = (l + r) / 2;
					if (arr[mid] == it.first) {
						break;
					} else if (arr[mid] > it.first) {
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}

				if (mid > 0 && mid < arr.size() - 1) {
					res++;
				}
			}
		}
	}
	cout << res << endl;

}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc = 1;
	//read(tc);
	for (int t = 1; t <= tc; t++) {
		//cout << "Case #" << t << ": ";
		solve();
	}
}

