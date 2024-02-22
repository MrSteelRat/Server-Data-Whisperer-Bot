//
// Created by Mr Steel Rat on 2/20/2024.
//

#ifndef FILESTATEMODULE_H
#define FILESTATEMODULE_H

#include <iostream>
#include <memory>
#include <string>

#include <tgbot/tgbot.h>


class FileStateModule {
    public:
        size_t creave_env_var(std::unique_ptr<std::string> name, std::unique_ptr<std::string> value);
        void send_message_to_admin(unsigned long long int chat_id, std::string * env_var_name, TgBot::Bot * bot, std::string * file_path, int flag);

        std::string * get_file_name();
        unsigned long long int get_folder_name(char * path, size_t size);
};



#endif //FILESTATEMODULE_H
