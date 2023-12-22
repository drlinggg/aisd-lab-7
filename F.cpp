#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

void get_number(string& first, ll& iter1, string& saved_number1, ll& pos1) {
    while(true) {
        if ((int) first[iter1] <= 57 && (int) first[iter1] >= 48) {
            saved_number1 += first[iter1];
            iter1++;
        }
        else {
            pos1 += stoi(saved_number1);
            saved_number1 = "";
            break;
        }
    }
}

signed main() {
    fast;
    ll f,s,c,iter1,iter2,count,pos1,pos2,prefpos1,prefpos2;
    iter1 = iter2 = count = pos1 = pos2 = prefpos1 = prefpos2 = 0;
    string saved_number1 = "";
    string saved_number2 = "";
    char saved1,saved2;
    string first,second;
    cin >> f >> s >> c;
    cin >> first >> second;
    while (true) {
        if (iter1 < first.size()-1 && iter2 < second.size()-1 && pos1 == pos2) {
            saved1 = first[iter1++];
            saved2 = second[iter2++];
            prefpos1 = pos1;
            prefpos2 = pos2;
            get_number(first, iter1, saved_number1, pos1);
            get_number(second, iter2, saved_number2, pos2);
        }
        else if (iter2 < second.size() - 1 && pos1 > pos2) {
            saved2 = second[iter2++];
            prefpos2 = pos2;
            get_number(second, iter2, saved_number2, pos2);
        }
        else if (iter1 < first.size()-1 && pos2 > pos1){
            saved1 = first[iter1++];
            prefpos1 = pos1;
            get_number(first, iter1, saved_number1, pos1);
        }
        if (saved1 == saved2 && (prefpos2 <= pos1 || prefpos1 <= pos2)) {
            count += min(pos1,pos2) - max(prefpos1,prefpos2)+1;
        }
        if (iter1 >= first.size()-1 && iter2 >= second.size()-1) {
            break;
        }
    }
    if (pos1-count < c) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
