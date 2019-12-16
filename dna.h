#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <fstream>
#include <cctype>
#include <stack>
using namespace std;

class dna {
   
private:
    string *seqtab;
    int seqSize;
public:
    dna(string dnainput){
        vector<string> nucleotides;
        for(int i=0; i < dnainput.length(); i++){
            string nuco;
            if(isalpha(dnainput.at(i))){
                nuco = tolower(dnainput.at(i));
                nucleotides.push_back(nuco);
            }
        }
        seqSize = nucleotides.size();
        seqtab = new string[seqSize];
        for(int i=0; i<seqSize; ++i){
            seqtab[i] = nucleotides.at(i);
        }
    }
    ~dna(){
        delete [] seqtab;
    }
    
    void reverse();
    void transcribe();
    string translate();
    void print();
    string getAA(string N, string L, string T);
};
#endif