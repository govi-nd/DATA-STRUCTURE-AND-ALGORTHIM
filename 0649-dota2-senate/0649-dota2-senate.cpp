class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ, direQ;
        int n = senate.size();

        // Store positions of R and D senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiantQ.push(i);
            else
                direQ.push(i);
        }

        // Simulation
        while (!radiantQ.empty() && !direQ.empty()) {
            int rFront = radiantQ.front();
            radiantQ.pop();

            int dFront = direQ.front();
            direQ.pop();

            // Senator with smaller index acts first
            if (rFront < dFront) {
                radiantQ.push(rFront + n);
            } 
            else {
                direQ.push(dFront + n);
            }
        }

        return radiantQ.empty() ? "Dire" : "Radiant";
    }
};