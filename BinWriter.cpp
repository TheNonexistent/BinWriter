#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    char* infname = new char[80];
    char* outfname = new char[80];
    fstream inputfile, outputfile;
    cout << "[+]Welcome To Binary Writer." << endl;
    cout << "Enter The Input File Name:";
    cin >> infname;
    cout << "\nEnter The Output File Name:";
    cin >> outfname;
    
    inputfile.open(infname, ios::in | ios::binary);
    outputfile.open(outfname, ios::out | ios::binary);
    
    if (!inputfile.is_open())
    {
        cerr << "/n[#]Cannot Open Input File.\n" "[#]Something Has Gone Wrong." << endl;
        cout << "[+]Exiting..." << endl;
        return 1; 
    }
    else
    {
        inputfile.seekg(0, inputfile.end);
        streamoff length = inputfile.tellg();
        cout << "/n[+]Files Successfully Opened." << endl;
        cout << "[-]InputFile: " << infname << " Size: " << length << endl;
        cout << "[-]OutputFile: " << outfname << endl;
        inputfile.seekg(0, inputfile.beg);
        int position;
        string data;
        cout << "\nEnter The Position You Want To Write In:";
        cin >> position;
        cout << "\nEnter Your Data:";
        cin >> data;
        char * buff = new char[length + data.length()];
        
        char cdata[data.length()];
        strcpy(cdata, data.c_str());
        
        for(int i = 0; i <= (data.length() - 1); i++)
        {
            *(buff + i) = cdata[i];
        }
        
        for (int i = data.length(); i < length + data.length(); i++)
        {   
            inputfile.read(buff + i, sizeof(char));
        }
        
        outputfile.write(buff, length + data.length());
        delete [] buff; 
        delete [] infname;
        delete [] outfname;
        cout << "[+]Successfully Wrote To File." << endl;
        return 0;
    }
}
