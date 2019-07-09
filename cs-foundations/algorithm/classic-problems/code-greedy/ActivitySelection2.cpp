#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
struct Pair
{
    // stores start time and finish time of the activities
    int start, finish;
};
 
// Activity-Selection problem
void selectActivity(vector<Pair> const &vec)
{
    // k keeps track of the index of the last selected activity
    int k = 0;
 
    // set to store the selected activities index
    set<int> out;
 
    // select 0 as first activity
    out.insert(0);
 
    // start iterating from the second element of
    // vector up to its last element
    for (int i = 1; i < vec.size(); i++)
    {
        // if start time of i'th activity is is greater or equal
        // to the finish time of the last selected activity, it
        // can be included in activities list
        if (vec[i].start >= vec[k].finish)
        {
            out.insert(i);
            k = i;    // update i as last selected activity
        }
    }
 
    for (int i: out) {
        cout << "{" << vec[i].start << ", " << vec[i].finish << "}" << '\n';
    }
}
 
// main function
int main()
{
    // vector of pairs with each pair storing start time
    // and finish time of the activities
    vector<Pair> activities =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    // Sort the activities according to their finishing time
    sort(activities.begin(), activities.end(),
        [](auto const &lhs, auto const &rhs) {
            return lhs.finish < rhs.finish;
        });
 
    selectActivity(activities);
 
    return 0;
}