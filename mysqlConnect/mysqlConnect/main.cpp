#include "StudentManager.h"


int main() {
	////���ĺ���
	//Student stu1{ 333,"aisheng","��һ��" };
	//StudentManager::GetInstance()->update_student(stu1);
	////���뺯��
	//Student stu2{ 333,"aisheng","��һ��" };
	//StudentManager::GetInstance()->insert_student(stu2);
	////ɾ������
	//Student stu{ 333,"aisheng","��һ��" };
	//StudentManager::GetInstance()->delete_student(333);


	vector<Student> ret = StudentManager::GetInstance()->get_students();

	for (auto& t : ret) {
		cout << t.student_id << ' ' << t.student_name << ' ' << t.class_id << endl;
	}

	return 0;
}