//Author: Niranjan A
//FCFS algorithm for process scheduling

#include<iostream>
#include<algorithm>
using namespace std;

class Process{
    public:
        int id; 
        int burstTime, waitingTime, turnAroundTime, arrivalTime;
};

bool operator<(const Process &a, const Process &b){
    return a.arrivalTime < b.arrivalTime;
}

int main(){
    int n, i, j;
    cout << "Enter the number of processes\n";
    cin >> n;
    Process p[n];
    cout << "For each process, enter its details\n";
    for(i=0; i<n; i++){
        cout << "ID: ";
        cin >> p[i].id;
        cout << "Arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst time: ";
        cin >> p[i].burstTime;        
    }

    sort(p, p+n);
    int t=0;

    for(i=0; i<n; i++){
        if(t < p[i].arrivalTime){
            t += p[i].arrivalTime - t;
        }
        p[i].waitingTime = t - p[i].arrivalTime;
        t += p[i].burstTime;
        p[i].turnAroundTime = t - p[i].arrivalTime;
    }

    int totalWaitTime = 0;
    int totalTurnArountTime = 0;

    for(i=0; i<n; i++){
        totalWaitTime += p[i].waitingTime;
        totalTurnArountTime += p[i].turnAroundTime;
        for(j=0; j<p[i].burstTime; j++){
            cout << " ";
            if(j==p[i].burstTime/2)
                cout << "P" << p[i].id;
        }
        cout << "|";
    }

    cout << endl << "ID\tArrival time\tBurst time\tWaiting time\tTurn around time\n";
    for(i=0; i<n; i++){
        cout << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].waitingTime << "\t\t" << p[i].turnAroundTime << endl;
    }

    float averageWaitingTime = (float)totalWaitTime/n;
    float averageTurnAroundTime = (float)totalTurnArountTime/n;
    cout << "Average waiting time : " << averageWaitingTime << endl;
    cout << "Average turn around time : " << averageTurnAroundTime << endl;

    return 0;
}
