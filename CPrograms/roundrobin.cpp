//Author: Niranjan A
//Round robin scheduling for processes

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Process{
    public:
        int id;
        int arrivalTime, burstTime, waitingTime, turnAroundTime, timeLeft, lastUsedTime;
        Process(){
            waitingTime = 0;
            lastUsedTime = 0;
        }
};

bool operator < (const Process &a, const Process &b){
    return a.arrivalTime < b.arrivalTime;
}

int main(){
    int n, i, j, quantum;
    cout << "Enter the number of processes\n";
    cin >> n;
    Process p[n];

    cout << "Enter the details of each of the process\n";
    for(i=0; i<n; i++){
        cout << "ID: ";
        cin >> p[i].id;
        cout << "Arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst time: :";
        cin >> p[i].burstTime;
        p[i].timeLeft = p[i].burstTime;
    }

    cout << "Enter the quantum: ";
    cin >> quantum;

    sort(p, p+n);
    vector<int> schedule(0);
    int t=0, count=0, index;
    for(i=0; count<n; i=(i+1)%n){
        if(p[count].arrivalTime > t){
            schedule.push_back(-1);
            t++;
            //t = p[count].arrivalTime;
        }
        if(p[i].arrivalTime <= t && p[i].timeLeft > 0){
            p[i].waitingTime += t - p[i].lastUsedTime;
            schedule.push_back(p[i].id);
            if(p[i].timeLeft > quantum){
                p[i].timeLeft -= quantum;    
                t += quantum;
                p[i].lastUsedTime = t;
            }
            else{
                t+= p[i].timeLeft;
                p[i].timeLeft = 0;
                p[i].turnAroundTime = t;
                cout << p[i].turnAroundTime << " ";
                count++;
            }
        }
    }

    cout << endl;
    for(i=0; i<schedule.size(); i++){
        cout << "P" << schedule[i] << " |";
    }

    int totalWaitingtime = 0;
    int totalTurnAroundTime = 0;
    float averageWaitingTime;
    float averageTurnAroundTime;
    cout << endl << "ID\tArrival time\tBurst time\tWaiting time\tTurn around time\n"; 
    for(i=0; i<n; i++){
        p[i].waitingTime -= p[i].arrivalTime;
        p[i].turnAroundTime -= p[i].arrivalTime;
        
        cout << "P" << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].waitingTime << "\t\t" << p[i].turnAroundTime << endl;
        
        totalWaitingtime += p[i].waitingTime;
        totalTurnAroundTime += p[i].turnAroundTime;
    }

    averageWaitingTime = (float)totalWaitingtime/n;
    averageTurnAroundTime = (float)totalTurnAroundTime/n;

    cout << "Average waiting time : " << averageWaitingTime << endl;
    cout << "Average turn around time: " << averageTurnAroundTime << endl;

    return 0;
}

