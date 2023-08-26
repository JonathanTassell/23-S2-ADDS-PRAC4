#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2){
    vector<int> outVector;
    vector<int> indexes; 

    bool flag; 
    bool substringFound = 0; 

    for(size_t i=0; i < s1.size(); i++){
        if(s1.at(i) == s2.at(0)){  
            indexes.push_back(i); 
            if(!flag){
                outVector.push_back(i); 
                flag = 1; 
            }
        }
    }

    int substrNum = 1; 
    int num = 0; 

    if(indexes.size()){
        //while substring has letters, loop
        while(s2.size()-1){
            size_t iter=0; 
            //loop until checked all indexes

            for(; iter < indexes.size();){
                //if next number in index is equal to next number in substr
                if (indexes.at(iter) + 1 < s1.size() && s1.at(indexes.at(iter) + 1) == s2.at(substrNum)){
                    indexes.at(iter)+=1; 
                    if(!substringFound){
                        num++;
                        outVector.push_back(indexes.at(iter)-num); 
                    }
                    substringFound = true; 
                    iter++; 
                }
                else{
                    vector<int>::iterator eraseAt = indexes.begin()+iter;
                    indexes.erase(eraseAt); 
                } 
            }
            s2 = s2.substr(substrNum, s2.size()); 

            if(!substringFound){
                outVector.push_back(-1); 
            }
            else substringFound = false; 
        }
    }

    return outVector; 
}


