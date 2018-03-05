//
// Created by Miroslav Kudrnac on 05/03/2018.
//

#ifndef SQLITE_SERVER_REQUESTHANDLER_H
#define SQLITE_SERVER_REQUESTHANDLER_H

#include <string>
#include <nlohmann/json.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "Response.h"
#include "IRequestHandler.h"

class RequestHandler final : public IRequestHandler
{
public:
    RequestHandler();

	//MARK: IRequestHandler
    std::unique_ptr<IResponse> handle_request(const std::string& req);

private:
    const nlohmann::json parse_request(const std::string& req);

    //handlers
    std::unique_ptr<IResponse> handle_query(const nlohmann::json& j);
    std::unique_ptr<IResponse> handle_list(const nlohmann::json& j);
    std::unique_ptr<IResponse> handle_delete_db(const nlohmann::json& j);

private:
    const std::map<std::string, boost::function<std::unique_ptr<IResponse>(const nlohmann::json&)>> m_map;
};


#endif //SQLITE_SERVER_REQUESTHANDLER_H
