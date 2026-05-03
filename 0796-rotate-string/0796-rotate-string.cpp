class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        
        int n = s.size();
        string doubled = s + s;
        for(int i = 0; i < n; i++){
            if(doubled.substr(i, n) == goal){
                return true;
            }
        }
        return false;
    }
};