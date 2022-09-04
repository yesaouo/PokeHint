#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void wordcase(int n,string pmhint){
    bool found = false;
    string pmname,dataptr="./pokedex/"+to_string(n)+".txt";
    ifstream pmdata;
    pmdata.open(dataptr);
    while(getline(pmdata,pmname)){
        for(int i=0; i<n; i++){
            if(pmhint[i]!='_'&&pmname[i]!=pmhint[i])break;
            if(i==n-1){
                found = true;
                cout<<"p!c "<<pmname<<endl;
            }
        }
    }
    if(!found)cout<<"Sorry, I can't find the pokemon."<<endl;
    pmdata.close();
}

int main() { 
	string pmhint;
	while(getline(cin,pmhint)){
        if(pmhint.find("The pokemon is ")==0){
            pmhint=pmhint.substr(15);
            pmhint.erase(pmhint.length()-1);
        }
        wordcase(pmhint.length(),pmhint);
	}
}