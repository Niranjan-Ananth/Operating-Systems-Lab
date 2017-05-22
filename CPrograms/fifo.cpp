//Author : Niranjan A
//Program to count number of page faults when fifo algorithm is used for page replacement

#include<iostream>
using namespace std;

int main(){
    int n, f, i, j;
    cout << "Enter the number of frames\n";
    cin >> f;
    cout<<"Enter the length of the reference string\n";
    cin >> n;
    int frames[f];
    for(i=0; i<f; i++){
        frames[i] = -1;
    }
    cout << "Enter the reference string, one digit after another\n";
    bool flag = false;
    int k=0, count=0;
    for(i=0; i<n; i++){
        int a;
        cin >> a;
        flag = false;
        for(j=0; j<f; j++){
            if(frames[j]==a){
                flag = true;
                break;
            }
        }
        if(!flag){
            frames[k] = a;
            k = (k+1)%f;
            count++;
        }
    }
    cout << "Number of page faults is : " << count << endl;

    return 0;
}

//Sample input: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//Sample Output: 15
