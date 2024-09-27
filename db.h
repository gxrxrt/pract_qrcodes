#ifndef DB_H
#define DB_H

#include <string>

#include <mysql/jdbc.h>

class Database {
public:
    Database();
    ~Database();

    bool verifyUserStatus(const std::string& uniqueId);

private:
    sql::Connection* con;
};

#endif
