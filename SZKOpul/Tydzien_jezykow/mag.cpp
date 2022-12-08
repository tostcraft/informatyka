#include<iostream>
using std::cout;
using std::cin;

/*char to index*/
int ctoi(char c){
    if((int)c > 96){
        return c-97;        
    }
    return c-38;  
}//0-26 a-z 27-52 A-Z

int magic_subs(std::string s){
    /*
    PART 1: Finding all characters and giving them a place in a counter table
    */
    int count = 1;
    int inds[53] = {0}; //indexes given in the counters table

    for(char c: s){
        int index = ctoi(c);
        if(inds[index]==0){
            inds[index] = count;
            count++;
        }
    }
    // for(int i = 0; i<53; i++){
    //     cout <<inds[i] <<" ";
    // }
    // cout <<"\n";
    /*
    PART 2: Finding all magical substrings
    */
    int magical_substrings = 0;

    for(int i = 0; i<s.size(); i++){
        int* counters = new int[count-1]{0};

        for(int j = i; j<s.size(); j++){
            // cout <<s[j] <<" " <<ctoi(s[j]) <<" " <<inds[ctoi(s[j])]-1 <<"\n";
            counters[inds[ctoi(s[j])]-1]++;
            //if(j-i<count-1) continue;

            bool is_magical = true;
            for(int z = 0; z<count-1; z++){
                // cout <<counters[z] <<" ";
                if(counters[0]!=counters[z]){
                    is_magical = false;
                }
            }
            // cout <<"\n";
            if(is_magical){
                magical_substrings++;
                // cout <<magical_substrings <<"\n";
            }
        }
        delete counters;
    }
    return magical_substrings;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;
    std::string s;
    cin >>s;

    int c = magic_subs(s);
    cout <<c <<"\n";
    
    return 0;
}
