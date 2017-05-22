//Author: Niranjan A
//Program to count the number of page faults when using LRU page replacement algorithm

#include<iostream>
using namespace std;
class Page{
    public:    
        int id; //Represents the page number
        int ltime; //Stores the time the page in the frame was last used
        Page(){
            ltime = 0;
        }
};

int main(){
    int n, f, i, j;
    cout << "Enter the number of frames\n";
    cin >> f;
    cout << "Enter the length of the reference string\n";
    cin >> n;
    Page frames[f];
    
    for(i=0; i<f; i++){
        frames[i].id = -1;
    }

    int count = 0, a;
    bool flag = false;
    cout << "Enter the reference string, one digit after another\n";
    for(i=1; i<=n; i++){    //Starting with i=1, and ending with i=n is necessary.
        cin >> a;
        flag = false;
        for(j=0; j<f; j++){
            if(frames[j].id==a){
                flag = true;
                frames[j].ltime = i;
                break;
            }
        }
        if(!flag){
            count++;
            int o, min = 999;
            //Find the least used page
            for(j=0; j<f; j++){
                if(frames[j].ltime < min){
                    min = frames[j].ltime;
                    o = j;
                }
            }
            //Replace the least used page
            frames[o].id = a;
            frames[o].ltime = i;
        }
    }
    cout << "Number of page faults: " << count << endl;

    return 0;
}

//Sample input: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//Sample Output: 12
