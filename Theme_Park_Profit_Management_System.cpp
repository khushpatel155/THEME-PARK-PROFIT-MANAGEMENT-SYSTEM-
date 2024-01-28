#include <bits/stdc++.h>
using namespace std;

int p[5];
int v[5], i;
float a[7];
float rideprofit;
int max_ans = INT_MAX;
float b[5];
int temp1;
int temp2;
int temp3;

void prize(int i)
{
    cin >> p[i];
}

void visitors(int i)
{
    cin >> v[i];
}

float profit(int i)
{
    rideprofit = v[i] * p[i];
    return rideprofit;
}

int main()
{
    cout << " Prizes of each rides\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "prize of ride " << i + 1 << ": Rs";
        prize(i);
    }
    cout << "\n\n";
    for (int i = 0; i < 5; i++)
    {
        b[i] = 0;
    }
    int days = 1;
    while (days <= 7)
    {
        cout << " PROFIT ANALYSIS OF DAY " << days << "\n\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Tickets sold Of Ride " << i + 1 << " is: ";
            visitors(i);
        }
        cout << "\n";
        float totalprofit = 0;
        for (int i = 0; i < 5; i++)
        {
            totalprofit += v[i] * p[i];
        }
        cout << "\n\n";
        max_ans = INT_MIN;
        for (int i = 0; i < 5; i++)
        {
            if (profit(i) > max_ans)
            {
                max_ans = profit(i);
                temp1 = i;
            }
        }
        float per1 = (profit(temp1) / totalprofit) * 100;
        cout << "> Total profit of day " << days << " is: " << totalprofit << " Rs.\n";
        cout << "> The most profitable ride is: " << temp1 + 1 << ".\n";
        cout << "> Total profit from the ride " << temp1 + 1 << " is: " << profit(temp1) << " Rs.\n";
        cout << "> The ride " << temp1 + 1 << " is contribute " << per1 << " percentage in the total profit of the day.\n\n";
        a[days - 1] = totalprofit;

        for (int i = 0; i < 5; i++)
        {
            b[i] += profit(i);
        }
        days++;
    }

    max_ans = INT_MIN;
    float sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += a[i];
        if (a[i] > max_ans)
        {
            max_ans = a[i];
            temp2 = i;
        }
    }
    max_ans = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (b[i] > max_ans)
        {
            max_ans = b[i];
            temp3 = i;
        }
    }

    cout << " WEEKLY PROFIT REPORT OF THE THEME PARK\n\n";
    float per2 = (b[temp3] / sum) * 100;
    cout << "> Total profit of the week is " << sum << " Rs.\n";
    cout << "> Record breaking day of the week is " << temp2 + 1 << " day.\n";
    cout << "> The most profitable ride of this week is ride no." << temp3 + 1 << ".\n";
    cout << "> Total profit from the ride " << temp3 + 1 << " in this week is " << b[temp3] << " Rs.\n";
    cout << "> Ride " << temp3 + 1 << " contributed " << per2 << " percentage in the total profit of the week.\n";

    return 0;
}
