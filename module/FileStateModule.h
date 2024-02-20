//
// Created by Mr Steel Rat on 2/20/2024.
//

#ifndef FILESTATEMODULE_H
#define FILESTATEMODULE_H

#include <iostream>
#include <memory>

#include <tgbot/tgbot.h>


class FileStateModule {
    public:
        size_t creave_env_var(std::unique_ptr<std::string> name, std::unique_ptr<std::string> value);
        void send_message_to_admin(unsigned long long int chat_id, std::string * env_var_name, TgBot::Bot * bot, std::string *);
};



#endif //FILESTATEMODULE_H
