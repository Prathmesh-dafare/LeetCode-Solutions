class Solution { 
public:

 bool isfreqsame(int freq1[] , int freq2[]){
    for(int i = 0 ; i< 26 ; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;

 }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0 ; i < s1.length(); i++){
            freq[s1[i] - 'a']++;
        }
        int windsize = s1.length();
        for(int i = 0 ; i<s2.length(); i++){
            int windindx = 0; 
            int idx = i;
            int windfreq[26] = {0};

            while(windindx < windsize && idx < s2.length()){
                windfreq[s2[idx]-'a']++;
                windindx++; idx++;
            }
            if(isfreqsame(freq , windfreq)){
                return true;
            }
        }
        return false;

    }
};