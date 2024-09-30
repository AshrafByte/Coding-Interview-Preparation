bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map <char,int> freq;
    int length = s.length();
    for (int i = 0 ; i < length ; i++ )
    {
        freq[s[i]]++;
        freq[t[i]]--;
    }
    
    for (auto const &e : freq)
        if (e.second != 0)
            return false;
    
    return true;
}
////////////////////////////
// another solution better for space 
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
        
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s == t;
}
