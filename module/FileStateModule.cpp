//
// Created by Mr Steel Rat on 2/20/2024.
//

#include <iostream>

#include "FileStateModule.h"



size_t FileStateModule::creave_env_var(std::unique_ptr<std::string> name_file, std::unique_ptr<std::string> value_file)
{
    size_t setup_env = setenv(name_file->c_str(), value_file->c_str(), 1);
    if(setup_env == 0) {
        std::cout << "Environment variable [" << *name_file << "] set successfully with value [" << *value_file << std::endl;
    }
    else {
        std::cout << "Failed to set environment variable [" << *name_file << "] with value [" << *value_file << "]";
    }

    std::cout.flush();
    
    return setup_env;
}
