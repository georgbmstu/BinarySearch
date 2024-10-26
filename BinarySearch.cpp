#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


static int search(const vector<int>& vec, int num, int l, int r) {
    if (l > r) {
        return -1;
    }
    int middle = l + (r - l) / 2;
    if (vec[middle] == num) {
        while (middle > 0 && vec[middle - 1] == num) {
            middle--;
        }
        return middle;
    }
    else if (vec[middle] < num) {
        return search(vec, num, middle + 1, r);
    }
    else {
        return search(vec, num, l, middle - 1);
    }
}
int main() {
    locale::global(locale(""));
    string line;
    getline(cin, line);
    istringstream strin(line);
    vector<int> sorted_vecay;
    int number;
    while (strin >> number) {
        sorted_vecay.push_back(number);
    }
    while (true) {
        getline(cin, line);
        if (line.substr(0, 6) == "search") {
            istringstream strin(line);
            string srch;
            int num;
            strin >> srch >> num; 
            int result = search(sorted_vecay, num, 0, sorted_vecay.size() - 1);
            cout << result << endl;
        }
    }
    return 0;
}
