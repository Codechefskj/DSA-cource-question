#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;  
        int primeCount = 0;
        int temp = x;

        for(int num = 2; num*num <= temp; num++){
            while(temp % num == 0){
                primeCount++;
                temp /= num;
            }
        }
        if(temp > 1) primeCount++; 

        if(primeCount >= k){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
