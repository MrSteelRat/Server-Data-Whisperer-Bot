#include <stdio.h>
#include <tgbot/tgbot.h>
#include "data_bot.h"

int main() {
  TgBot::Bot bot(TOKEN);
  try {
    printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
    TgBot::TgLongPoll longPoll(bot);
    while (true) {
      printf("Long poll started\n");
      longPoll.start();
    }
  } catch (TgBot::TgException &e) {
    printf("error: %s\n", e.what());
  } catch (...) {
    std::cout << "error 2" << "\n";
  }
  return 0;
}