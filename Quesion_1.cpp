//question link-https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

string get_group_id(string &s){
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string res="";
        for(int i=0;i<freq.size();i++){
            res=res+to_string(freq[i])+"^";
        }
        return res; 
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,int> ump;
        vector<vector<string>> ans;
        for(int i=0;i<string_list.size();i++){
            string k=get_group_id(string_list[i]);
            //jab pehli pehli baar koi naya group insert kr rhe to 
            //ans ki size badhani hogi aur wo group kis index me hai
            //wo bhi to decide krna hoga na.
            if(ump.find(k)==ump.end()){
                ans.push_back({});
                //ump[k] me store hua hai ki kya index hoga k wale 
                //group ka ans vector me.
                ump[k]=(int)ans.size()-1;
            }
            ans[ump[k]].push_back(string_list[i]);
        }
        return ans;
    }