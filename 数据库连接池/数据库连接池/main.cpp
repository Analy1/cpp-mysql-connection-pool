#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Connection.h"
#include"CommonConnectionPool.h"
using namespace std;

int main()
{
	/*Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
		"zhang san", 20, "male");

	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);*/

	clock_t begin = clock();
	ConnectionPool* cp = ConnectionPool::getConnectionPool();

	//多线程测试（4线程）
#if 0

	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	//多线程
	thread t1([&]()
		{
			ConnectionPool* cp = ConnectionPool::getConnectionPool();

			for (int i = 0;i < 250;++i)
			{

				char sql[1024] = { 0 };
				sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
					"zhang san", 20, "male");
				shared_ptr< Connection> sp = cp->getConnection();

				sp->update(sql);
			}
		});

	thread t2([&]()
		{
			ConnectionPool* cp = ConnectionPool::getConnectionPool();

			for (int i = 0;i < 250;++i)
			{

				char sql[1024] = { 0 };
				sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
					"zhang san", 20, "male");
				shared_ptr< Connection> sp = cp->getConnection();

				sp->update(sql);
			}
		});

	thread t3([&]()
		{
			ConnectionPool* cp = ConnectionPool::getConnectionPool();

			for (int i = 0;i < 250;++i)
			{

				char sql[1024] = { 0 };
				sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
					"zhang san", 20, "male");
				shared_ptr< Connection> sp = cp->getConnection();

				sp->update(sql);
			}
		});

	thread t4([&]()
		{
			ConnectionPool* cp = ConnectionPool::getConnectionPool();

			for (int i = 0;i < 250;++i)
			{
				char sql[1024] = { 0 };
				sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
					"zhang san", 20, "male");
				shared_ptr< Connection> sp = cp->getConnection();

				sp->update(sql);
			}
		});

	t1.join();
	t2.join();
	t3.join();
	t4.join();
#endif

	for (int i = 0;i < 1000;++i)
	{
		
		/*Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
			"zhang san", 20, "male");

		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		conn.update(sql);*/

		shared_ptr< Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
			"zhang san", 20, "male");
		sp->update(sql);
	}
	clock_t end = clock();
	cout << (end - begin) <<"ms" << endl;
	return 0;
}//10147 6600