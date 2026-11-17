
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        long long sum = 0;

        vector<bool> used(matchsticks.size(), false);

        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }

        if (sum % 4 != 0)
            return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        long long side = sum / 4;

        if (matchsticks[0] > side)
            return false;

        return recur(0, 0, side, matchsticks, used, 0);
    }

    bool recur(int index, int cur, int side,
               vector<int>& v, vector<bool>& use,
               int side_counter) {

        if (side_counter == 3) {
            return true;
        }

        if (cur == side) {
            return recur(0, 0, side, v, use, side_counter + 1);
        }

        for (int i = index; i < v.size(); i++) {

            if (use[i])
                continue;

            if (cur + v[i] > side)
                continue;

            use[i] = true;

            if (recur(i + 1, cur + v[i], side,
                      v, use, side_counter)) {
                return true;
            }

            use[i] = false;
        }

        return false;
    }
};
