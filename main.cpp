#include "dna.h"

int main(int argc, char *argv[]){
    if (argc < 2){
        cout << "Input error: Not enough Arguments." << endl;
        return 0;
    }
    string command = argv[1];
    string dnainput;
    vector<string> dnaVecSec;
    
    if (command == "file"){
        ifstream datainput;
        datainput.open("DNAinput.txt");
        if(datainput.is_open()){
            while(getline(datainput, dnainput)){
                dnaVecSec.push_back(dnainput);
            }
            datainput.close();
            stringstream dd;
            for (int i=0; i<dnaVecSec.size(); ++i){
                dd << dnaVecSec.at(i);
            }
            dnainput = dd.str();
        }
        else{
            cout << "file could not open, sorry." << endl;
            return 0;
        }
    }
    else{
        cout << "enter your DNA string: " << endl;
        getline(cin, dnainput);
    }
        dna *sequence = new dna(dnainput);
        string contcomm;
        string funcomm;
    do{
        cout << "What would you like to do with this DNA data???" << endl << "Enter one of the following:" << endl << "--- reverse" << endl << "--- transcribe" << endl << "--- translate" << endl << "--- print" << endl << "Command = ";
        cin >> funcomm;
        if(funcomm == "reverse"){
            sequence->reverse();
            cout << "Reverse Complete!" << endl;
        }
        else if (funcomm == "transcribe"){
            sequence->transcribe();
            cout << "Transcription Complete!" << endl;
        }
        else if(funcomm == "translate"){
            string translation = sequence->translate();
            cout << "Translation Complete!" << endl << translation << endl;
        }
        else if(funcomm == "print"){
            sequence->print();
        }
        else{
            cout << "Not a valid command." << endl;
        }
        
        cout << "Do you want to perform another action?  --  Enter yes or no  --";
        cin >> contcomm;
    }while(contcomm == "yes" || contcomm == "y");

    cout << "Final DNA Sequence:" <<endl;
    sequence->print();
    return 0;
}