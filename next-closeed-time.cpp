class Solution {
public:
    string nextClosestTime(string time) {
        int hrs = (time[0] - '0') * 10 + time[1] - '0';
        int mins = (time[3] - '0') * 10 + time[4] - '0';

        // store all available characters
        unordered_set<char> dict;
        for (char c : time)
            dict.insert(c);

        for (;;) {
            // increase the time
            if (++mins == 60) {
                mins = 0;
                hrs = (hrs + 1) % 24;
            }

            // construct current time
            string newTime = "" + string(1, '0' + hrs / 10) + string(1, '0' + hrs % 10);
            newTime += ":" + string(1, '0' + mins / 10) + string(1, '0' + mins % 10);

            // check for validity
            bool fail = false;
            for (char c : newTime) {
                 if (dict.find(c) == dict.end()) {
                     fail = true;
                     break;
                 }
            }
            // if it is valid, then return the result and exit
            if (!fail)
                return newTime;
        }
    }
};
