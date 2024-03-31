mySQLConnet
简介：Implement CRUD (Create, Read, Update, Delete) functionalities using C++ to connect to a MySQL database.
      本项目使用c++语言实现数据库的增删改查，涉及技术：单例设计模式、cpp封装类、vector容器的c++11遍历特性、SQL的连接、SQL的增删改查语句
代码讲解：
StudentManager.h中
  单例设计模式，通过将构造函数和析构函数设置为私有，这个类防止了外部代码直接创建 `StudentManager` 的新实例。相反，外部代码必须通过调用 
  `GetInstance` 方法来获取对唯一实例的引用。这样就确保了整个类只有一个实例接口给外面。
  static StudentManager* GetInstance() {
    static StudentManager StudentManager;
    return &StudentManager;
  }
  将要实现的函数都封装成成员函数
  public:
  	bool insert_student(Student& stu);
  	bool update_student(Student& stu);
  	bool delete_student(int student_id);
  	vector<Student> get_students(string condition = "");
  c++11遍历新特性：auto& t：这里auto是自动类型推导，它告诉编译器自动推断变量t的类型，而&表示引用，ret表示遍历的容器，整个循环将遍历ret容器
  中的每个元素，引用它们作为t，然后打印出它们的属性。
  for (auto& t : ret) {
		cout << t.student_id << ' ' << t.student_name << ' ' << t.class_id << endl;
	}
 
StudentManager.cpp中
  mySQL连接方式
  mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0)
  mySQL语句：
  插入
  INSERT INTO students (student_id, student_name, class_id) VALUES (?, ?, ?)
  更新
  UPDATE students SET student_name = ?, class_id = ? WHERE student_id = ?
  删除
  DELETE FROM students WHERE student_id = ?
  查询
  SELECT * FROM students WHERE [condition]
  
