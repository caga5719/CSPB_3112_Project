#include<string>
#include<vector>

using namespaced std;


class Pair
{
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};
class Solution
{
private:
    void quickSortHelper(vector<Pair> &pairs, int s, int pivot_idx)
    {
        if (pivot_idx - s + 1 <= 1)
        {
            return;
        }

        int lef_end = s;
        int i = s;

        int pivot_key = pairs[pivot_idx].key;

        while (i < pivot_idx)
        {
            // check if current index is greater than the pivot
            // capture lesser key and place it on the left side of the list
            if (pairs[i].key < pivot_key)
            {
                std::swap(pairs[i], pairs[lef_end]);
                lef_end++;
            }
            i++;
        }
        std::swap(pairs[pivot_idx], pairs[lef_end]);
        std::cout << "List seperated \n"
                  << "Left side: is S == " << s << ". Pivot_idx == " << lef_end - 1 << endl;
        quickSortHelper(pairs, s, lef_end - 1);
        std::cout << "Right side: is S == " << lef_end + 1 << ". Pivot_idx == " << pivot_idx << endl;
        quickSortHelper(pairs, lef_end + 1, pivot_idx);
        return;
    }

public:
    vector<Pair> quickSort(vector<Pair> &pairs)
    {
        int pivot = pairs.size() - 1;
        int s = 0;
        quickSortHelper(pairs, s, pivot);
        return pairs;
    }
};
