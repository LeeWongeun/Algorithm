#include <iostream>

using namespace std;

int main() {
    int n, arr[10000];
    int fib[4000] = { 0 };
    fib[0] = fib[1] = 1;
    int check=2;

    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cout << "1 0\n";
        }
        else if(arr[i]==1){
            cout << "0 1\n";
        }
        else {
            if (check < arr[i]) {
                for (int j = check; j < arr[i]; j++) {
                    if (j == 0 || j == 1) {
                        fib[j] = 1;
                    }
                    else if (j == 2) {
                        fib[j] = 2;
                    }
                    else {
                        fib[j] = fib[j - 1] + fib[j - 2];
                        check = j;
                    }
                }
            }
            cout << fib[arr[i]-2] << " " << fib[arr[i]-1] << "\n";
        }
    }
}