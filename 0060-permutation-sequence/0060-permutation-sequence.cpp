class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> numbers;
        int fact = 1;

        // Store numbers from 1 to n
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }

        numbers.push_back(n);

        // Convert k to 0-based index
        k--;

        string ans = "";

        while (true) {

            // Select index
            ans += to_string(numbers[k / fact]);

            // Remove used number
            numbers.erase(numbers.begin() + k / fact);

            // If no numbers left
            if (numbers.size() == 0)
                break;

            // Update k
            k = k % fact;

            // Update factorial
            fact = fact / numbers.size();
        }

        return ans;
    }
};