class Solution {
    public boolean isPalindrome(String s) {
        int  l = 0;
        int n = s.length();
        String s1 = "";
        for(int i = 0; i<n; i++){
            char ch = s.charAt(i);
            if(Character.isLetterOrDigit(ch)){
                s1+=Character.toLowerCase(ch);
            }
        }
        int r = s1.length()-1;
        while(l<r){
            if(s1.charAt(l)!=s1.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}