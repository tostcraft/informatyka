#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;


int main(){

    std::vector<std::vector<std::string>> anagram_classes;
    int n;
    cin>>n;
    std::string *data = new std::string[n];
    for(int i = 0; i<n;i++){
        cin>>data[i];
    }

    for(int j = 0; j<n; j++)
    {
        std::string str = data[j];
        std::string cop = str;
        std::sort(cop.begin(), cop.end());
        bool found = false;
        for(int i=0; i<anagram_classes.size(); i++){
            if(anagram_classes[i][0] == cop){
                found = true;
                bool copied = false;
                for(int k = 1; k<anagram_classes[i].size(); k++){
                    if(anagram_classes[i][k] == str){
                        copied = true;
                        break;
                    }
                }
                if(copied){
                    break;
                }
                anagram_classes[i].push_back(str);
            }
        }
        if(!found || anagram_classes.size()==0){
            std::vector<std::string> new_class;
            new_class.push_back(cop);
            new_class.push_back(str);
            anagram_classes.push_back(new_class);
        }
    }

    for(std::vector<std::string> &vec: anagram_classes){
        vec.erase(vec.begin());
        std::sort(vec.begin(), vec.end());
    }

    std::sort(anagram_classes.begin(), anagram_classes.end());
    for(std::vector<std::string> vec : anagram_classes){
        for(std::string s:vec){
            cout <<s <<" ";
        }
        cout <<"\n";
    }

    cout <<"\n";
    return 0;
}