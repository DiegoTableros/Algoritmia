#include <bits/stdc++.h>

using namespace std;
deque <int> dequeue;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Metemos un diez inicialmente
    dequeue.push_front(10);
    cout << dequeue[0] << "\n";
    for(int i=1; i<=9; i++) {
        if(i%2==0) {
            dequeue.push_front(i);
        } else {
            dequeue.push_back(i);
        }
    }
    for(unsigned int i=0; i<dequeue.size(); i++) {
        cout << dequeue[i] << " ";
    }
    return 0;
}
