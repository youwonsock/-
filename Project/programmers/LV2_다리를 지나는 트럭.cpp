#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
    Data(int time, int truckWeight)
    {
        entryTime = time;
        weight = truckWeight;
    }

    int entryTime = 0;
    int weight = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int waitIDX = 0;
    int loadedWeight = truck_weights[waitIDX];

    queue<Data> progress;
    progress.push(Data(answer, truck_weights[waitIDX++]));

    while (!progress.empty())
    {
        Data front = progress.front();

        if(bridge_length <= (answer - front.entryTime))
        {
            progress.pop();
            loadedWeight -= front.weight;
        }

        if(truck_weights.size() > waitIDX && progress.size() < bridge_length)
        {
            if((loadedWeight + truck_weights[waitIDX]) <= weight)
            {
                loadedWeight += truck_weights[waitIDX];
                progress.push(Data(answer, truck_weights[waitIDX++]));
            }
        }

        ++answer;
    }
    

    return answer;
}