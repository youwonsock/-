#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
어느 왕국에 하나 이상의 도시들이 있습니다. 왕국의 왕은 새 도시를 짓기로 결정하였습니다. 해당 도시를 짓기 위해서는 도시를 짓는 장소에 금 a kg과 은 b kg이 전달되어야 합니다.

각 도시에는 번호가 매겨져 있는데, i번 도시에는 금 g[i] kg, 은 s[i] kg, 그리고 트럭 한 대가 있습니다. i번 도시의 트럭은 오직 새 도시를 짓는 건설 장소와 i번 도시만을 왕복할 수 있으며, 편도로 이동하는 데 t[i] 시간이 걸리고, 최대 w[i] kg 광물을 운반할 수 있습니다. (광물은 금과 은입니다. 즉, 금과 은을 동시에 운반할 수 있습니다.) 모든 트럭은 같은 도로를 여러 번 왕복할 수 있으며 연료는 무한대라고 가정합니다.

정수 a, b와 정수 배열 g, s, w, t가 매개변수로 주어집니다. 주어진 정보를 바탕으로 각 도시의 트럭을 최적으로 운행했을 때, 새로운 도시를 건설하기 위해 금 a kg과 은 b kg을 전달할 수 있는 가장 빠른 시간을 구해 return 하도록 solution 함수를 완성해주세요.

제한사항
	0 ≤ a, b ≤ 109
	1 ≤ g의 길이 = s의 길이 = w의 길이 = t의 길이 = 도시 개수 ≤ 105
	0 ≤ g[i], s[i] ≤ 109
	1 ≤ w[i] ≤ 102
	1 ≤ t[i] ≤ 105
	a ≤ g의 모든 수의 합
	b ≤ s의 모든 수의 합
*/

/*
* 04/21
* 모든 경우의 수를 탐색하는것은 불가능하니 운반에 걸리는 시간을 이분 탐색으로 탐색
* 
* 최대로 걸리는 시간
* 필요한 광물의 전체(금 + 은) 양 = A 
* 한번에 옮길 수 있는 양 = B 
* 한번 움직이는데 걸리는 시간 = C
*
* [ 필요한 광물을 모두 옮기는데 필요한 시간 ]
* 약 : (C * 2) * (A / B) + C
* = (10^5 * 2) * ((2 * 10^9) / 1) + 10^5
* = (4 * 10^14 + 10^5)
* 
* 해당시간에 운반 가능한 금, 은, 총 운반량을 확인하여
* 입력값보다 크다면 true 아니면 false
*/

bool Search(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long Mid)
{
    long long Total_Gold = 0;
    long long Total_Silver = 0;
    long long Total_Mineral = 0;

    for (int i = 0; i < g.size(); i++)
    {
        long long Time = t[i];

        long long Round_Time = Time * 2;
        long long Move_Cnt = Mid / Round_Time;
        if (Mid % Round_Time >= Time) Move_Cnt++;
        long long Max_Take = w[i] * Move_Cnt;

        Total_Gold += min((long long)g[i], Max_Take);
        Total_Silver += min((long long)s[i], Max_Take);
        Total_Mineral += min((long long)g[i] + s[i], Max_Take);
    }

    if (Total_Gold >= a && Total_Silver >= b && Total_Mineral >= a + b) return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    long long answer = -1;
    long long Start = 0;
    long long End = 4 * 10e14 + 10e5;
    answer = End;

    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        if (Search(a, b, g, s, w, t, Mid) == true)
        {
            answer = min(answer, Mid);
            End = Mid - 1;
        }
        else 
            Start = Mid + 1;
    }

    return answer;
}
