/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
 int find2(int low, int high, int target, MountainArray& arr) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr.get(mid) == target) {
                ans = mid;
               return ans ;
            } else if (arr.get(mid) < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int find(int low, int high, int target, MountainArray& arr) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr.get(mid) == target) {
                ans = mid;
                return ans ;
            } else if (arr.get(mid) < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int func(MountainArray& arr) {
        int low = 0;
        int high = arr.length() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // if (arr.get(mid) > arr.get(mid - 1) &&
            //     arr.get(mid) > arr.get(mid + 1))
            //     return mid;
             if (arr.get(mid) < arr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int findInMountainArray(int target, MountainArray& arr) {
        int n = arr.length();
        int ind = func(arr);
        cout << ind << endl;
        int ans = find(0, ind, target, arr);
        if (ans != -1)
            return ans;
        else
            return find2(ind + 1, n - 1, target, arr);
    }
};