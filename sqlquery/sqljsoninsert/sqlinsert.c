#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#include "sqlinsert.h"
#include "json.h"

int main(int argc, char** argv)
{

	MYSQL* conn, connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
	struct DB_CONN db_info;
	int query_stat;
	char* sql;

	JSON_Value* JsonValue;
	JSON_Object* JsonObject;

	const char* name;
	const char* phone;
	const char* grade;
	
	db_info.host = "localhost";
	db_info.user = "root";
	db_info.passwd = "1234";
	db_info.dbname = "test";

	mysql_init(&connection); // sql init

	conn = mysql_real_connect(&connection, db_info.host, db_info.user, db_info.passwd,
		       	db_info.dbname, 3306, (char*)NULL, 0);
	if(conn == NULL) {
		printf("connection fail !\n");
		return -1;
	}
	printf("connection success!\n");

	JsonValue = json_parse_file("example.json");
	JsonObject = json_value_get_object(JsonValue);

	name = json_object_get_string(JsonObject, "name");
	phone = json_object_get_string(JsonObject, "phone");
	grade = json_object_get_string(JsonObject, "grade");

	printf("name [%s] phone [%s] grade [%s]\n", name, phone, grade);
	
#if(1)
	sprintf(sql, "insert into person (name, phone) value ('%s', '%s')\n", name, phone); 
	sql[strlen(sql)-1] = '\0';
	printf("[%s]\n", sql);
	query_stat = mysql_query(conn, sql);
	if (query_stat != 0) {
		printf("mysql query error!\n");
	}
	printf("mysql insert success!\n");

	sprintf(sql, "insert into grade (name, grade) value ('%s', '%s')\n", name, grade); 
	sql[strlen(sql)-1] = '\0';
	printf("[%s]\n", sql);
	query_stat = mysql_query(conn, sql);
	if (query_stat != 0) {
		printf("mysql query error!\n");
	}
	printf("mysql insert success!\n");
#endif

	mysql_close(conn);

	return 0;
}
