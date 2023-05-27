#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<iomanip>
#include <windows.h>
using namespace std;

// Tài khoản Học sinh
struct StudentAccount {
    string username;
    string password;
};

//Tài khoản Giáo viên
struct TeacherAccount {
    string username;
    string password;
};






// Dang Nhap
void registerStudent();
bool studentLogin(const string& username, const string& password);
void changeStudentPassword(const string& username, const string& newPassword);
void viewStudentProfile(const string& username);

void registerTeacher();
bool teacherLogin(const string& username, const string& password);
void changeTeacherPassword(const string& username, const string& newPassword);
void viewTeacherProfile(const string& username);
void menulogin();

// MAU SAC
void setColor(int color);



















