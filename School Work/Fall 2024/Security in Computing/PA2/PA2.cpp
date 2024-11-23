#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//file processing function
vector<char> fileHandling(const char* filename, int bitSize) {
    vector<char> fileData;
    ifstream FILE(filename);
    //check if file is open
    if (!FILE.is_open()) {
        cerr << "Could not open file, try again?" << endl;
        return {};
    }
    //determine file size
    FILE.seekg(0, ios::end);
    int size = FILE.tellg();
    FILE.seekg(0, ios::beg);

    fileData.resize(size);
    FILE.read(fileData.data(), size);
    
    // Calculate padding based on size
    int paddingNeeded = 0;
    if (bitSize == 8) paddingNeeded = 0;
    else if (bitSize == 16) paddingNeeded = size % 2 ? 1 : 0;
    else if (bitSize == 32) paddingNeeded = (4 - (size % 4)) % 4;

   
    fileData.insert(fileData.end(), paddingNeeded, 'X');
    return fileData;
}

    //calculation function
int processing(const vector<char>& fileContents, int bit) {
    unsigned int count = 0;
    //if 8
    if (bit == 8) {
        for (char c : fileContents) {
            count += static_cast<unsigned char>(c);
        }
        count &= 0xFF;
    } 
    //ig 16
    else if (bit == 16) {
        for (size_t i = 0; i < fileContents.size(); i += 2) {
            unsigned short twoBytes = static_cast<unsigned char>(fileContents[i]);
            if (i + 1 < fileContents.size()) {
                twoBytes = (twoBytes << 8) | static_cast<unsigned char>(fileContents[i + 1]);
            }
            count += twoBytes;
        }
        count &= 0xFFFF; 
    } 
    //if 32
    else if (bit == 32) {
        for (size_t i = 0; i < fileContents.size(); i += 4) {
            unsigned int fourBytes = static_cast<unsigned char>(fileContents[i]);
            if (i + 1 < fileContents.size()) {
                fourBytes = (fourBytes << 8) | static_cast<unsigned char>(fileContents[i + 1]);
            }
            if (i + 2 < fileContents.size()) {
                fourBytes = (fourBytes << 8) | static_cast<unsigned char>(fileContents[i + 2]);
            }
            if (i + 3 < fileContents.size()) {
                fourBytes = (fourBytes << 8) | static_cast<unsigned char>(fileContents[i + 3]);
            }
            count += fourBytes;
        }
        count &= 0xFFFFFFFF;
    } else {
        cerr << "Valid checksum sizes are 8, 16, or 32\n";
        return -1;
    }

    return count;
}

//printing function
void printFileContents(const vector<char>& fileContents) {
    int count = 0;
    for (char c : fileContents) {
        cout << c;
        if (++count % 80 == 0) {
            cout << endl;
        }
    }
    if (count % 80 != 0) {
        cout << endl; 
    }
}
//driver
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Not enough arguments\n";
        return 1;
    }

    /
    int bit = atoi(argv[2]);
    if (bit != 8 && bit != 16 && bit != 32) {
        cerr << "Valid checksum sizes are 8, 16, or 32\n";
        return 1;
    }

    
    vector<char> fileContents = fileHandling(argv[1], bit);
    if (fileContents.empty()) {
        return 1;
    }

    
    printFileContents(fileContents);

   
    int checksum = processing(fileContents, bit);
    if (checksum == -1) {
        return 1;  // Error
    }

    
    printf("%2d bit checksum is %8lx for all %4d chars\n", bit, checksum, static_cast<int>(fileContents.size()));

    return 0;
}
