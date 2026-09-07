class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        
        for(int i = 0; i<n; i++){
            char ch = chars[i];  //let every charcher in the chars
            int count = 0;   // this is the initial count of character
            
            while(i< n && chars[i] == ch){ // comparing the character upto size of chars and upto we have the same charecter 
                count++; i++; // calculating the count 
            }

            if(count == 1){
                chars[idx++] = ch; // only the character store at the chars of idx 
                      // if store on element at one index we should have to increase the index 
            }
            else{ // if the count is not equal to the 1 then we have to store the character as well as the count in the chars 
                chars[idx++] = ch; // it store the charecter at the index idx 
                      // increase the index by one 
                string str = to_string(count); // as the count is in the form of the integer we need to conver that integer into the string hence the to_string(count); is used
                for(char dig : str){ // now the count should be 2 digits or 3 digits we have to store every digit in the saperate index 
                    chars[idx++] = dig;
                
                }
            }
            i--; // while comparing the index i reached to the extra i++ so we have to do the i--
        }
         chars.resize(idx); // resize the string becouse the string get compress
         return idx; // returnig the idx value becouse the idx contain the last element value i.e in the copress string
    }
};