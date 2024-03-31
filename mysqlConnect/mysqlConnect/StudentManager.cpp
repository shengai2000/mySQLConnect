#include "StudentManager.h"

StudentManager::StudentManager()
{
	con = mysql_init(NULL);

	//设置编码,GBK属于UTF-8
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0)) {
		
		exit(1);
	}
}

StudentManager::~StudentManager()
{
	mysql_close(con);
}

bool StudentManager::insert_student(Student& stu)
{
	char sql[256];

	sprintf_s(sql, sizeof(sql), "insert into students (student_id,student_name,class_id) values(%d,'%s','%s')", stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());

	if (mysql_query(con, sql)) {
		fprintf(stderr, "Failed to connect to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::update_student(Student& stu)
{
	char sql[256];

	sprintf_s(sql, sizeof(sql), "UPDATE students SET student_name = '%s',class_id = '%s'where student_id = %d",
		stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

	if (mysql_query(con, sql)) {
		fprintf(stderr, "Failed to update to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;

}

bool StudentManager::delete_student(int student_id)
{
	char sql[256];

	sprintf_s(sql, "DELETE FROM students WHERE student_id = %d",student_id);

	if (mysql_query(con, sql)) {
		fprintf(stderr, "Failed to delete to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

vector<Student> StudentManager::get_students(string condition)
{
	vector<Student> stuList;
	char sql[256];

	sprintf_s(sql, "SELECT * FROM students %s", condition.c_str());

	if (mysql_query(con, sql)) {
		fprintf(stderr, "Failed to select to database:Error:%s\n", mysql_error(con));
		{
			return {};
		}
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res))) {
		Student stu;
		stu.student_id = atoi(row[0]);//int 转string
		stu.student_name = row[1];
		stu.class_id = row[2];

		stuList.push_back(stu);
	}

	return stuList;
}



//query实现
//void StudentManager::update_student(Student* t) {
//    string query = "UPDATE students SET student_name = '" + t->student_name +
//        "', class_id = '" + t->class_id + "' WHERE student_id = '" + to_string(t->student_id) + "';";
//    if (mysql_query(con, query.c_str())) {
//        cerr << "MySQL query error: " << mysql_error(con) << endl;
//    }
//}
//
//void StudentManager::delete_student(int student_id) {
//    string query = "DELETE FROM students WHERE student_id = '" + to_string(student_id) + "';";
//    if (mysql_query(con, query.c_str())) {
//        cerr << "MySQL query error: " << mysql_error(con) << endl;
//    }
//}
//
//vector<Student> StudentManager::get_students(string condition) {
//    vector<Student> students;
//    string query = "SELECT * FROM students";
//    if (!condition.empty()) {
//        query += " WHERE " + condition;
//    }
//    query += ";";
//
//    if (mysql_query(con, query.c_str())) {
//        cerr << "MySQL query error: " << mysql_error(con) << endl;
//        return students;
//    }
//
//    MYSQL_RES* result = mysql_store_result(con);
//    if (result == NULL) {
//        cerr << "MySQL store result error: " << mysql_error(con) << endl;
//        return students;
//    }
//
//    MYSQL_ROW row;
//    while ((row = mysql_fetch_row(result))) {
//        Student student;
//        student.student_id = atoi(row[0]);
//        student.student_name = row[1];
//        student.class_id = row[2];
//        students.push_back(student);
//    }
//
//    mysql_free_result(result);
//    return students;
//}