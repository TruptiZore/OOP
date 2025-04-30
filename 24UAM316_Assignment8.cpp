#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

    // Caesar Cipher Encryption
    string encrypt(string msg) {
        for (size_t i = 0; i < msg.length(); ++i)
            msg[i] += encryptionKey;
        return msg;
    }

    // Caesar Cipher Decryption
    string decrypt(string msg) {
        for (size_t i = 0; i < msg.length(); ++i)
            msg[i] -= encryptionKey;
        return msg;
    }

public:
    // Constructor to initialize filename and encryption key
    FileEncryptor(string fname, int key) : filename(fname), encryptionKey(key) {}

    // Encrypt and write to file
    void encryptAndWrite(const string& message) 
	{
        ofstream file(filename.c_str(), ios::app);

        if (file.is_open()) 
		{
            string encrypted = encrypt(message);
            file << encrypted;
            file.close();
            cout << "Message successfully encrypted and stored in " << filename << endl;
        } 
		else 
		{
            cout << "Error opening file for writing." << endl;
        }
    }

    // Read encrypted data and decrypt
    string readAndDecrypt() {
        ifstream file(filename.c_str(),ios::app);
        string encrypted;
        if (file.is_open()) {
            getline(file, encrypted);
            file.close();
            return decrypt(encrypted);
        } else {
            cout << "Error opening file for reading." << endl;
            return "";
        }
    }

    // Display decrypted file content
    void displayFileContents() {
        string decrypted = readAndDecrypt();
        if (!decrypted.empty()) {
            cout << "Decrypted Message: " << decrypted << endl;
        }
    }
};

int main() 
{
    FileEncryptor fe("data.txt", 3); // Caesar shift of 3

    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    fe.encryptAndWrite(message);

    cout << "\nReading and decrypting file..." << endl;
    fe.displayFileContents();

    return 0;
}

