#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    switch(n){
        case 1:
        cout<<"Stop";
        break;
        
        case 2:
        cout<<"Standby";
        break;
        
        case 3:
        cout<<"Go";
        break;
        
        
        default:
        cout<<"Unknown";
    }
    

    return 0;
}