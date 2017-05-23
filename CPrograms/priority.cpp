//Author: Niranjan A
//Priority scheduling of processes

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Process{
    public:
        int id;
        int arrivalTime, burstTime, waitingTime, turnAroundTime, timeLeft;
        int prior;
        Process(){
            waitingTime = 0;
            turnAroundTime = 0;
        }
};

bool operator < (const Process &a, const Process &b){
    return a.arrivalTime < b.arrivalTime;
}

int getNextProcess(Process p[], int t, int n){
    int index=-1, i;
    int smallest = 11;
    for(i=0; i<n; i++){
        if(p[i].arrivalTime <= t && p[i].timeLeft > 0){
            if(p[i].prior < smallest){
                smallest = p[i].prior;
                index = i;
            }
        }
    }
    return index;
}

int main(){
    int n, i, j;
    cout << "Enter the number of processes\n";
    cin >> n;
    Process p[n];
    cout << "Enter the details of each of the process\n";
    for(i=0; i<n; i++){
        cout << "ID: ";
        cin >> p[i].id;
        cout << "Arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst time: ";
        cin >> p[i].burstTime;
        p[i].timeLeft = p[i].burstTime;
        cout << "Enter the priority (1-10): ";
        cin >> p[i].prior;
    }

    sort(p, p+n);
    int count=0, t=0;
    int index;

    vector<int> schedule(0);

    while(count < n){
        index = getNextProcess(p, t, n);
        if(index!=-1){
            schedule.push_back(p[index].id);
            p[index].timeLeft--;
            if(p[index].timeLeft==0){
                count++;
                p[index].turnAroundTime = t - p[index].arrivalTime + 1;
            }
            for(i=0; i<n; i++){
                if(i!=index && p[i].arrivalTime <= t && p[i].timeLeft > 0){
                    p[i].waitingTime++;
                }
            }
        }
        else{
            schedule.push_back(-1);
        }
        t++;
    }

    for(i=0; i<schedule.size(); i++){
        if(schedule[i]!=-1)
            cout << "P" << schedule[i] << " |";
        else 
            cout << " " << " " << " |";
    }
    cout << endl;

    int totalWaitingtime = 0;
    int totalTurnAroundTime = 0;
    float averageWaitingTime;
    float averageTurnAroundTime; 
    
    cout << endl << "ID\tArrival time\tBurst time\tWaiting time\tTurn around time\n"; 
    for(i=0; i<n; i++){
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
