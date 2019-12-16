#include "dna.h"

    
void dna::reverse(){
    stack<string> letters;
    for(int i = 0; i<seqSize; ++i){
        letters.push(seqtab[i]);
    }
    for(int i = 0; i<seqSize; ++i){
        seqtab[i] = letters.top();
        letters.pop();
    }
}

void dna::transcribe(){
    string N;
    for(int i=0; i<seqSize; ++i){
        N = seqtab[i];
        if(N == "a") {
            seqtab[i] = "u";
        }
        else if(N == "t" || N == "u") {
            seqtab[i] = "a";
        }
        else if(N == "g"){ 
            seqtab[i] = "c";
        }
        else if(N == "c") {
            seqtab[i] = "g";
        }
        else{
            seqtab[i] = "*";
        }
    }
}

string dna::getAA(string N, string L, string T){
    string e = "error";
    if(N!="a" && N!="u" && N!="g" && N!="c"){
        return e;
    }
    else if(L!="a" && L!="u" && L!="g" && L!="c"){
        return e;
    }
    else if(T!="a" && T!="u" && T!="g" && T!="c"){
        return e;
    }
    if(N == "u"){
        if(L == "u"){
            if(T == "u"){
                return "PHE";
            }
            if(T == "c"){
                return "PHE";
            }
            if(T == "a"){
                return "LEU";
            }
            if(T == "g"){
                return "LEU";
            }
         }
        if(L == "c"){
            if(T == "u"){
                return "SER";
            }
            if(T == "c"){
                return "SER";
            }
            if(T == "a"){
                return "SER";
            }
            if(T == "g"){
                return "SER";
            }
        }
        if(L == "a"){
            if(T == "u"){
                return "TYR";
            }
            if(T == "c"){
                return "TYR";
            }
            if(T == "a"){
                return "STOP";
            }
            if(T == "g"){
                return "STOP";
            }
        }
        if(L == "g"){
            if(T == "u"){
                return "CYS";
            }
            if(T == "c"){
                return "CYS";
            }
            if(T == "a"){
                return "STOP";
            }
            if(T == "g"){
                return "TRP";
            }
        }
    }
    if(N == "c"){
        if(L == "u"){
            if(T == "u"){
                return "LEU";
            }
            if(T == "c"){
                return "LEU";
            }
            if(T == "a"){
                return "LEU";
            }
            if(T == "g"){
                return "LEU";
            }
        }
        if(L == "c"){
            if(T == "u"){
                return "PRO";
            }
            if(T == "c"){
                return "PRO";
            }
            if(T == "a"){
                return "PRO";
            }
            if(T == "g"){
                return "PRO";
            }
        }
        if(L == "a"){
            if(T == "u"){
                return "HIS";
            }
            if(T == "c"){
                return "HIS";
            }
            if(T == "a"){
                return "GLN";
            }
            if(T == "g"){
                return "GLN";
            }    
        }
        if(L == "g"){
            if(T == "u"){
                return "ARG";
            }
            if(T == "c"){
                return "ARG";
            }
            if(T == "a"){
                return "ARG";
            }
            if(T == "g"){
                return "ARG";
            }    
        }
    }
    if(N == "a"){
        if(L == "u"){
            if(T == "u"){
                return "ILE";
            }
            if(T == "c"){
                return "ILE";
            }
            if(T == "a"){
                return "ILE";
            }
            if(T == "g"){
                return "MET";
            }
        }
        if(L == "c"){
            if(T == "u"){
                return "THR";
            }
            if(T == "c"){
                return "THR";
            }
            if(T == "a"){
                return "THR";
            }
            if(T == "g"){
                return "THR";
            }    
        }
        if(L == "a"){
            if(T == "u"){
                return "ASN";
            }
            if(T == "c"){
                return "ASN";
            }
            if(T == "a"){
                return "LYS";
            }
            if(T == "g"){
                return "LYS";
            }    
        }
        if(L == "g"){
            if(T == "u"){
                return "SER";
            }
            if(T == "c"){
                return "SER";
            }
            if(T == "a"){
                return "ARG";
            }
            if(T == "g"){
                return "ARG";
            }   
        }
    }
    if(N == "g"){
        if(L == "u"){
            if(T == "u"){
                return "VAL";
            }
            if(T == "c"){
                return "VAL";
            }
            if(T == "a"){
                return "VAL";
            }
            if(T == "g"){
                return "VAL";
            }
        }
        if(L == "c"){
            if(T == "u"){
                return "ALA";
            }
            if(T == "c"){
                return "ALA";
            }
            if(T == "a"){
                return "ALA";
            }
            if(T == "g"){
                return "ALA";
            }    
        }
        if(L == "a"){
            if(T == "u"){
                return "ASP";
            }
            if(T == "c"){
                return "ASP";
            }
            if(T == "a"){
                return "GLU";
            }
            if(T == "g"){
                return "GLU";
            }    
        }
        if(L == "g"){
            if(T == "u"){
                return "GLY";
            }
            if(T == "c"){
                return "GLY";
            }
            if(T == "a"){
                return "GLY";
            }
            if(T == "g"){
                return "GLY";
            }    
        }
    }
}

string dna::translate(){
    int fake = seqSize%3;
    fake+=3;
    stringstream ss;
    for (int i=0; i<seqSize-fake; i+=3){
        ss << getAA(seqtab[i], seqtab[i+1], seqtab[i+2]) << " + ";
    }
    ss << getAA(seqtab[seqSize-fake], seqtab[seqSize-fake+1], seqtab[seqSize-fake+2]) << endl;
    return ss.str();
}

void dna::print(){
    cout << endl;
    int extra = seqSize%10;
    int overline = seqSize%50;
    for(int l=0; l<seqSize-overline; l+=50){
        for(int i=l; i<l+50; i+=10){
            for(int j=i; j<i+10; ++j){
                cout << seqtab[j];
            }
            cout << " ";
        }
        cout << endl;
    }
    for(int i=seqSize-overline; i<seqSize-extra; i+=10){
        for(int j=i; j<i+10; ++j){
            cout << seqtab[j];
        }
        cout << " ";
    }
    for(int i=seqSize-extra; i<seqSize; ++i){
        cout << seqtab[i];
    }
    cout << endl << endl;
}