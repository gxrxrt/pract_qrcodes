#include "db.h"
#include <iostream>

Database::Database() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "root");
        con->setSchema("pract_qr_codes");
    } catch (sql::SQLException& e) {
        std::cerr << "Ошибка подключения к базе данных: " << e.what() << std::endl;
    }
}

Database::~Database() {
    if (con) {
        delete con;
    }
}

bool Database::verifyUserStatus(const std::string& uniqueId) {
    bool status = false;
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT status FROM users WHERE unique_id = ?");
        pstmt->setString(1, uniqueId);
        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next()) {
            status = res->getBoolean("status");
        }

        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        std::cerr << "Ошибка выполнения запроса: " << e.what() << std::endl;
    }

    return status;
}
