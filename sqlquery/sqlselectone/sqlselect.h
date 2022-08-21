#ifndef __SQLSELECT_H__
#define __SQLSELECT_H__

struct DB_CONN {
	char* host;
	char* user;
	char* passwd;
	char* dbname;
};


int main(int argc, char** argv);
#endif


