//Author: Niranjan A
//SJF process scheduling

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Process{
    public:
        int id;
        int arrivalTime, burstTime, waitingTime, turnAroundTime, timeLeft ,lastUsedTime;
        Process(){
            waitingTime = 0;
            turnAroundTime = 0;
        }
};

bool operator < (const Process &a, const Process &b){
    return a.arrivalTime < b.arrivalTime;
}

int getNextProcess(Process p[], int t, int n){
    int i, index=-1, shortest=999;
    for(i=0; i<n; i++){
        if(p[i].arrivalTime <= t && p[i].timeLeft > 0){
            if(p[i].timeLeft < shortest){
                shortest = p[i].timeLeft;
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
    }
    int t=0, count=0;
    vector<int> schedule(0);
    int index;
    while(count < n){
        index = getNextProcess(p, t, n);
        if(index!=-1){
            schedule.push_back(p[index].id);
            p[index].timeLeft -= 1;
            if(p[index].timeLeft == 0){
                p[index].turnAroundTime = t - p[index].arrivalTime + 1;
                count++;
            }
            for(i=0; i<n; i++){
                if(i != index && p[i].arrivalTime <= t && p[i].timeLeft > 0)
                    p[i].waitingTime++;
            }
        }
        else{
            schedule.push_back(index);
        }
        t++;
    }
    
    cout << endl << "Blank space represents idle cpu" << endl;
    for(i=0; i<schedule.size(); i++){
        if(schedule[i]!=-1)
            cout << "P" << schedule[i]<<" |";
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
