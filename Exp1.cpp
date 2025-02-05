#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;


void caps(vector<string> &vec){
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].length();j++){
            if(vec[i][j]>='a' && vec[i][j]<='z'){
                vec[i][j]=vec[i][j]-32;
            }
        }   
    }
}
int vow(vector<string> vec){
    int count=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].length();j++){
            char curr=vec[i][j];
            if(vec[i][j]>='A' &&  vec[i][j]<='Z'){
                curr=vec[i][j]+32;
            }
            if(curr=='a' || curr=='e' || curr=='i' || curr=='o'|| curr=='u'){
                count++;
                printf("%c",curr);
            }
        }
    }
    return count;
}

bool comp(char x){
    int curr=x;
    if(curr>=33 && curr<=47 || curr>=91 && curr<=96 || curr>=58 && curr<=64){
        return true;
    }
    return false;
}
int special(vector<string> vec){
    int count=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].size();j++){
            if(comp(vec[i][j])){
                count++;
                printf("%c",vec[i][j]);
            }
        }
    }
    return count;
}

int spaces(vector<string> vec){
    int count=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].length();j++){
            if(vec[i][j]==' '){
                count++;
            }
        }
    }
    return count;
}
int tabs(vector<string> vec){
    int count=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].length();j++){
            if(vec[i][j]=='\t'){
                count++;
            }
        }
    }
    return count;
}
int newline(vector<string> vec){
    int count=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].length();j++){
            if(vec[i][j]=='\n'){
                count++;
            }
        }
        count++;
    }
    return count;
}

int main() {
    int n;
    vector<string> vec;
    while(true){
        string curr;
        getline(cin,curr);
        if(curr==""){
            break;
        }
        vec.push_back(curr);
    }
    cout << vow(vec) << " is the number of vowels" << endl;
    cout << special(vec) << " is the number of special characters" << endl;
    cout << spaces(vec) << " is the number of spaces" << endl;
    cout << tabs(vec) << " is the number of tabs" << endl;
    cout << newline(vec) << " is the number of newlines" << endl;
    
    caps(vec);
    cout << "Text after converting to uppercase:" << endl;
    for (const string& line : vec) {
        cout << line << endl;
    }
    
}