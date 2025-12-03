class Solution {
public:

    void buildAns(stack<string> &s, string &ans) {
        if (s.empty()) {
            return;
        }
        string minPath = s.top(); 
        s.pop();
        buildAns(s, ans);
        ans += minPath;
    }

    string simplifyPath(string path) {

        stack<string> s;
        int i = 0;

        while (i < path.size()) {

            int start = i;
            int end = i + 1;

            // Move until next '/'
            while (end < path.size() && path[end] != '/') {
                ++end;
            }

            string minPath = path.substr(start, end - start);
            i = end;

            // Skip "/" and "/."
            if (minPath == "/" || minPath == "/.") {
                continue;
            }

            // Normal path (e.g., "/a", "/b")
            if (minPath != "/..") {
                s.push(minPath);
            }
            // Handle "/.."
            else if (!s.empty()) {
                s.pop();
            }
        }

        string ans = s.empty() ? "/" : "";
        buildAns(s, ans);

        return ans;
    }
};