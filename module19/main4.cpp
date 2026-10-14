#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout << "Input path file: ";
    string path;
    cin >> path;

    ifstream file;

    file.open(path);

    if (!file.is_open()){
        cout << "Error path. Try again\n";\
        cout << "Input path file: ";
        cin >> path;
    }

    char buffer[4];
    file.read(buffer, sizeof(buffer));

    string fileType = path.substr(path.length() - 3, 3);
    bool isPng = (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' && fileType == "png");
    file.close();


    cout << (isPng ? "Yes, it is png file" : "No, it is not png file");
    return 0;
}