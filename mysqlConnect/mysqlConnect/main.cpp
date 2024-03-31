#include "StudentManager.h"


int main() {
	////更改函数
	//Student stu1{ 333,"aisheng","软工一班" };
	//StudentManager::GetInstance()->update_student(stu1);
	////插入函数
	//Student stu2{ 333,"aisheng","软工一班" };
	//StudentManager::GetInstance()->insert_student(stu2);
	////删除函数
	//Student stu{ 333,"aisheng","软工一班" };
	//StudentManager::GetInstance()->delete_student(333);


	vector<Student> ret = StudentManager::GetInstance()->get_students();

	for (auto& t : ret) {
		cout << t.student_id << ' ' << t.student_name << ' ' << t.class_id << endl;
	}

	return 0;
}