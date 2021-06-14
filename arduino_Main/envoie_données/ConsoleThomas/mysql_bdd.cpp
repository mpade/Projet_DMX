#include "mysql_bdd.h"

mysql_bdd::mysql_bdd()
{
	mysql = mysql_init(NULL);
}

int mysql_bdd::connectMYSQL()
{
	if (!mysql_real_connect(this->mysql, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
		return 0;
	
	else
		return 1;

}

std::vector<MYSQL_ROW> mysql_bdd::getSelectrequet(std::string requet)
{
	std::vector<MYSQL_ROW> Result;
	mysql_query(mysql, requet.c_str());

	MYSQL_RES *result = NULL;
	result = mysql_store_result(mysql);

	for (int i = 0; i < result->row_count; i++) 
		Result.push_back(mysql_fetch_row(result));

	return Result;
}
