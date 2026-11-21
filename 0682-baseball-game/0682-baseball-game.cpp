
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int a = ans.top();
                ans.pop();

                int b = ans.top();
                ans.pop();

                ans.push(b);
                ans.push(a);
                ans.push(a + b);
            }
            else if (operations[i] == "D") {
                ans.push(ans.top() * 2);
            }
            else if (operations[i] == "C") {
                ans.pop();
            }
            else {
                ans.push(stoi(operations[i]));
            }
        }

        int sum = 0;

        while (!ans.empty()) {
            sum += ans.top();
            ans.pop();
        }

        return sum;
    }
};
