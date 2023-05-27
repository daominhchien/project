#include"thuvien.h"


// Hàm kiểm tra tên đăng nhập đã tồn tại chưa
bool isUsernameTaken(const string& username, const string& filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);

        if (username == savedUsername) {
            file.close();
            return true;  // Tên đăng nhập đã tồn tại
        }
    }

    file.close();
    return false;  // Tên đăng nhập chưa tồn tại
}

// Hàm đăng ký tài khoản Học sinh mới
void registerStudent() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (isUsernameTaken(username, "student_accounts.txt")) {
        cout << "Username is already taken. Please choose a different username." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("student_accounts.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Student account registered successfully!" << endl;
}
// Hàm kiểm tra đăng nhập Học sinh
bool studentLogin(const string & username, const string & password) {
    ifstream file("student_accounts.txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername && password == savedPassword) {
            file.close();
            return true;  // Đăng nhập thành công
        }
    }

    file.close();
    return false;  // Đăng nhập thất bại
}

// Hàm đổi mật khẩu Học sinh
void changeStudentPassword(const string& username, const string& newPassword) {
    ifstream inputFile("student_accounts.txt");
    ofstream outputFile("temp.txt");

    string line;

    while (getline(inputFile, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername) {
            outputFile << savedUsername << " " << newPassword << endl;
        }
        else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("student_accounts.txt");
    rename("temp.txt", "student_accounts.txt");
}

// Hàm hiển thị thông tin hồ sơ Học sinh
void viewStudentProfile(const string& username) {
    ifstream file("student_accounts.txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername) {
            cout << "Username: " << savedUsername << endl;
            cout << "Password: " << savedPassword << endl;
            break;
        }
    }

    file.close();
}

// Hàm đăng ký tài khoản Giáo viên 
void registerTeacher() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (isUsernameTaken(username, "teacher_accounts.txt")) {
        cout << "Username is already taken. Please choose a different username." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("teacher_accounts.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Teacher account registered successfully!" << endl;
}

// Hàm kiểm tra đăng nhập Giáo viên
bool teacherLogin(const string & username, const string & password) {
    ifstream file("teacher_accounts.txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername && password == savedPassword) {
            file.close();
            return true;  // Đăng nhập thành công
        }
    }

    file.close();
    return false;  // Đăng nhập thất bại
}

// Hàm đổi mật khẩu Giáo viên
void changeTeacherPassword(const string& username, const string& newPassword) {
    ifstream inputFile("teacher_accounts.txt");
    ofstream outputFile("temp.txt");

    string line;

    while (getline(inputFile, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername) {
            outputFile << savedUsername << " " << newPassword << endl;
        }
        else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("teacher_accounts.txt");
    rename("temp.txt", "teacher_accounts.txt");
}

// Hàm hiển thị thông tin hồ sơ Giáo viên
void viewTeacherProfile(const string& username) {
    ifstream file("teacher_accounts.txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string savedUsername = line.substr(0, pos);
        string savedPassword = line.substr(pos + 1);

        if (username == savedUsername) {
            cout << "Username: " << savedUsername << endl;
            cout << "Password: " << savedPassword << endl;
            break;
        }
    }

    file.close();
}

// Hàm menu
void menulogin() {
    int choice;
    int luachon;
    string username, password, newPassword;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    saved_attributes = consoleInfo.wAttributes;

    cout << setw(75) << " ================================ " << endl;
    cout << setw(75) << " |            PORTAL            | " << endl;
    cout << setw(75) << " ================================ " << endl << endl;


    SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);
    cout << setw(75) << " ===============================" << endl;
    cout << setw(75) << "   Chon 1: Ban la sinh vien     " << endl;
    cout << setw(75) << "   Chon 2: Ban la giang vien    " << endl;
    cout << setw(75) << " ===============================" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, saved_attributes);
    cout << "      Lua chon cua ban: ";
    cin >> luachon;
    if (luachon == 1)
    {
        
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        cout << setw(75) << " =================================== " << endl;
        cout << setw(75) << "      = 1. Register Account          " << endl;
        cout << setw(75) << "      = 2. Login                     " << endl;
        cout << setw(75) << "      = 3. Thay doi mat khau         " << endl;
        cout << setw(75) << "      = 4. View Profile              " << endl;
        cout << setw(75) << "      = 5. Logout                    " << endl;
        cout << setw(75) << " =================================== " << endl;
        SetConsoleTextAttribute(hConsole, saved_attributes);
        while (true)
        {
            cout << "   =  Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1: 
                system("cls");
                cout << setw(75) << " ================================ " << endl;
                cout << setw(75) << " |            REGISTER          | " << endl;
                cout << setw(75) << " ================================ " << endl << endl;
                registerStudent();
                break;
            case 2:
                system("cls");
                cout << setw(75) << " ================================ " << endl;
                cout << setw(75) << " |            LOGIN             | " << endl;
                cout << setw(75) << " ================================ " << endl << endl;
                cout << "Student Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (studentLogin(username, password)) {
                    cout << "Student Login successful!" << endl;
                }
                else {
                    cout << "Student Login failed. Please try again." << endl;
                }
                break;
            case 3:
                system("cls");
                cout << setw(75) << " ================================ " << endl;
                cout << setw(75) << " |            CHANGE PASS       | " << endl;
                cout << setw(75) << " ================================ " << endl << endl;
                cout << "Enter student username: ";
                cin >> username;
                cout << "Enter new password: ";
                cin >> newPassword;
                changeStudentPassword(username, newPassword);
                cout << "Student password changed successfully!" << endl;
                break;
            case 4:
                system("cls");
                cout << setw(75) << " ================================ " << endl;
                cout << setw(75) << " |            VIEW PROFILE       | " << endl;
                cout << setw(75) << " ================================ " << endl << endl;
                cout << "Enter student username: ";
                cin >> username;
                viewStudentProfile(username);
                break;

            case 5:
                cout << "Logged out." << endl;
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

            }

        }

    }

    else if (luachon == 2)
    {
        cout << " =================================== " << endl;
        cout << "1. Register Student Account" << endl;
        cout << "2. Teacher Login" << endl;
        cout << "3. Thay doi mat khau Giang vien" << endl;
        cout << "4. View Teacher Profile" << endl;
        cout << "5. Logout" << endl;
        cout << " =================================== " << endl;
        while (true)
        {
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: 
                registerTeacher();
                break;

            case 2:
                cout << "Teacher Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (teacherLogin(username, password)) {
                    cout << "Teacher Login successful!" << endl;
                }
                else {
                    cout << "Teacher Login failed. Please try again." << endl;
                }
                break;
            case 3:
                cout << "Enter teacher username: ";
                cin >> username;
                cout << "Enter new password: ";
                cin >> newPassword;
                changeTeacherPassword(username, newPassword);
                cout << "Teacher password changed successfully!" << endl;
                break;
            case 4:
                cout << "Enter teacher username: ";
                cin >> username;
                viewTeacherProfile(username);
                break;
            case 5:
                cout << "Logged out." << endl;
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }


    }
}


   


void setColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
}


