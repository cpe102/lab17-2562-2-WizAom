#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
string change(string s){
    int x=0;
    while(s[x]){
        s[x]=toupper(s[x]);
        x++;
    }
    return s;
}
int main(){
    ifstream f("name_score.txt");
    string s,grade;
    vector<string> vname;
    vector<string> vgrade;
    char name[100];
    int n1,n2,n3;
    while(getline(f,s)){
        sscanf(s.c_str(),"%[^:]:%d %d %d",name,&n1,&n2,&n3);
        vname.push_back(name); 
        int g=n1+n2+n3;
        if(g>=80) grade="A";
        else if(g>=70) grade="B";
        else if(g>=60) grade="C";
        else if(g>=50) grade="D";
        else if(g<50) grade="F"; 
        vgrade.push_back(grade); 
    }
    string nname;
    cout << "Please input your command : ";
    getline(cin,nname);
    cout << "-----------------------------------" << "\n";
    string s1,s2;
    while(1){
        int idx=nname.find(" ");
        string t1=change(nname.substr(0,idx));
        string t2=change(nname.substr(idx+1,nname.size()));
        if(t1=="GRADE"){
            int a=0;
            for(int i=0;i<vgrade.size();i++){
                if(t2==change(vgrade[i])){
                    cout << vname[i] << endl ;
                    a++;
                }
            }if(a==0) cout << "Cannot Found." << "\n";  
            cout << "-----------------------------------" << "\n";
        }else if(t1=="NAME"){
            int a=0;
            for(int i=0;i<vname.size();i++){
                if(t2==change(vname[i])){
                    cout << vname[i] << "'s grade = " << vgrade[i] << endl;
                    a++;
                }
            }if(a==0) cout << "Cannot Found." << "\n";  
            cout << "-----------------------------------" << "\n";
        }else if(t1=="EXIT"){
            break;
        }else cout << "Invalid Command" << endl;
        break;
    }
    return 0;
}