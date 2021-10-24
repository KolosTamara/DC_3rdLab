#include <iostream>
#include <vector>
using namespace std;


vector<int> sort(vector<int> &array);
vector<int> merge(vector<int> &left, vector<int> &right);

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++){
        cin >> vect[i];
    }
    vect = sort(vect);
    for (int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    return 0;
}
vector<int> sort(vector<int> &array){
    if (array.size() == 1) {
        return array;
    }
    vector<int> left(array.begin(), array.begin() + array.size() / 2);
    vector<int> right(array.begin() + array.size() / 2, array.end());
    left = sort(left);
    right = sort(right);
    return merge(left, right);
}

vector<int> merge(vector<int> &left, vector<int> &right){
    int n = left.size();
    int m = right.size();
    vector<int> merged;
    int i = 0;
    int j = 0;
    while (i < n || j < m){
        if (((left[i] < right[j]) && (i < n)) || j >= m){
            merged.push_back(left[i]);
            i++;
        }
        else {
            merged.push_back(right[j]);
            j++;
        }
    }
    return merged;
}
