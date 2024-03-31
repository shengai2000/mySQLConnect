#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Student {
	int student_id;
	string student_name;
	string class_id;
}Student;

class StudentManager
{

public:
	static StudentManager* GetInstance() {
		static StudentManager StudentManager;
		return &StudentManager;
	}
public:
	bool insert_student(Student& stu);
	bool update_student(Student& stu);
	bool delete_student(int student_id);
	vector<Student> get_students(string condition = "");
private:
	StudentManager();
	~StudentManager();
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "Qwert147258.";
	const char* database_name = "database_test";
	const int port = 3306;
};

