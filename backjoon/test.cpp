#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

ll H_swap, L_swap, H_cmp, L_cmp;

ll partition_Hoare(vector<ll> &v, ll low, ll high)
{
    ll pivot = v[low];
    ll i = low - 1, j = high + 1;
    while (1)
    {
        while (1)
        {
            H_cmp++;
            i++;
            if (pivot <= v[i])
                break;
        }

        while (1)
        {
            H_cmp++;
            j--;
            if (pivot >= v[j])
                break;
        }

        if (i < j)
        {
            H_swap++;
            swap(v[i], v[j]);
        }
        else
            return j;
    }
}

ll partition_Lomuto(vector<ll> &v, ll low, ll high)
{
    ll i = low + 1, j = low;
    while (i <= high)
    {
        L_cmp++;
        if (v[low] > v[i])
        {
            j++;
            L_swap++;
            swap(v[i], v[j]);
        }
        i++;
    }

    swap(v[low], v[j]);
    L_swap++;
    return j;
}

void quicksort_Hoare(vector<ll> &v, ll low, ll high)
{
    if (low >= high)
        return;

    ll mid = partition_Hoare(v, low, high);
    quicksort_Hoare(v, low, mid);
    quicksort_Hoare(v, mid + 1, high);
}

void quicksort_Lomuto(vector<ll> &v, ll low, ll high)
{

    if (low >= high)
        return;

    ll mid = partition_Lomuto(v, low, high);
    quicksort_Lomuto(v, low, mid - 1);
    quicksort_Lomuto(v, mid + 1, high);
}

int main(void)
{
    ll TC;
    cin >> TC;

    ll n;
    while (TC--)
    {
        H_swap = 0, L_swap = 0, H_cmp = 0, L_cmp = 0;
        cin >> n;
        vector<ll> v1(n, 0), v2(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> v1[i];
            v2[i] = v1[i];
        }
        quicksort_Hoare(v1, 0, n - 1);
        quicksort_Lomuto(v2, 0, n - 1);

        cout << H_swap << ' ' << L_swap << ' ' << H_cmp << ' ' << L_cmp << '\n';
    }
    return 0;
}