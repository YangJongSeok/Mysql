#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#include "sqlselect.h"

int main(int argc, char** argv)
{

	MYSQL* conn, connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
	struct DB_CONN db_info;
	int query_stat;
	char query[1024];

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

// 전체 출력

	strcpy(query, "select A.no, A.name, A.phone, B.grade from person A left outer join grade B on A.name = B.name");

	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		printf("mysql query error!\n");
	}
	printf("select success !\n");

	result = mysql_store_result(conn);

	printf("%10s %-20s %-20s %-20s\n", "no", "name", "phone", "grade");

	while( (row = mysql_fetch_row(result)) != NULL )
	{
		printf("%10s %-20s %-20s %-20s\n", row[0], row[1], row[2], row[3]);
	}

	mysql_free_result(result);

	mysql_close(conn);
	

	return 0;
}
