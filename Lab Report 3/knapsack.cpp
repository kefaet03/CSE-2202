#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("knapsack.txt", "r", stdin);
    int n;
    int k;
    cin >> n >> k;
    vector<pair<double, double>> per(n);
    for (int i = 0; i < n; i++)
    {
        cin >> per[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> per[i].second;
    }

    sort(per.begin(), per.end(), [&](pair<double, double> &a, pair<double, double> &b)
         { return (a.second / a.first) > (b.second / b.first); });

    double total_weight = 0, total_benefit = 0;
    for (int i = 0; i < n; i++)
    {
        if (total_weight < k)
        {
            int temp = min(k - total_weight, per[i].first);
            double ratio = per[i].second / per[i].first;
            total_benefit += temp * ratio;
            cout << temp << " " << temp * ratio << "\n";
            total_weight += temp;
        }
        else
            break;
    }
    cout << total_benefit << endl;
}