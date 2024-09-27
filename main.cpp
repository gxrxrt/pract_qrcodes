#include "httplib.h"
#include "auth.h"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/auth", [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("id")) {
            std::string uniqueId = req.get_param_value("id");
            try {
                std::string response = handleAuthRequest(uniqueId);
                res.set_content(response, "text/html");
            } catch (const std::exception& e) {
                std::cerr << "Ошибка обработки запроса: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("<h1>Внутренняя ошибка сервера</h1>", "text/html");
            }
        } else {
            res.set_content("<h1>Недостаточно данных для авторизации</h1>", "text/html");
        }
    });

    std::cout << "Сервер запущен на http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
