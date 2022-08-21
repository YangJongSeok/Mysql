#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include "sqlinsert.h"

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

	query_stat = mysql_query(conn, 
			"insert into person (name, phone) value ('gunhee', '010-7354-7375')");
	if (query_stat != 0) {
		printf("mysql query error!\n");
	}
	printf("mysql insert success!\n");

	mysql_close(conn);
	

	return 0;
}
