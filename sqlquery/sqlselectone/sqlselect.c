#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include "sqlselect.h"

int main(int argc, char** argv)
{

	MYSQL* conn, connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
	struct DB_CONN db_info;
	int query_stat;

	mysql_init(&connection); // sql init
	
	db_info.host = "localhost";
	db_info.user = "root";
	db_info.passwd = "1234";
	db_info.dbname = "test";

	conn = mysql_real_connect(&connection, db_info.host, db_info.user, db_info.passwd,
		       	db_info.dbname, 3306, (char*)NULL, 0);
	if(conn == NULL) {
		printf("connection fail !\n");
		return -1;
	}
	printf("connection success!\n");

// 한건 출력, 변수에 담기	
	query_stat = mysql_query(conn, "select * from person where name='jongseok'");
	if (query_stat != 0) {
		printf("mysql query error!\n");
	}

	result = mysql_store_result(conn);
	printf("%10s %-20s %-20s\n", "num", "name", "phone");

	row = mysql_fetch_row(result);
	if(row == NULL) {
		printf("조회된 결과가 없습니다.\n");
		return -1;
	}
	printf("%10s %-20s %-20s\n", row[0], row[1], row[2]);

	char* name = NULL;
	char* phone = NULL;

	name = row[1];
	phone = row[2];

	printf("name [%s] phone [%s]\n", name, phone);


	mysql_free_result(result);

	mysql_close(conn);
	

	return 0;
}
