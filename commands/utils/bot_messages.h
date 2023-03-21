#ifndef BOT_MESSAGES_H
#define BOT_MESSAGES_H

#include <tgbot/tgbot.h>

class BotMessages {
public:
    static void startMessage(TgBot::Bot* bot, int64_t chatId, TgBot::ChatMember::Ptr user, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static void editStartMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::ChatMember::Ptr user, TgBot::InlineKeyboardMarkup::Ptr keyboard);
    
    static void developersEdit(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static void printToS(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static void printConfigPanel(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static void editConfigPanel(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyBoard);

    static void badCommandArgs(TgBot::Bot* bot, int64_t chatId);

    static void phraseHasErrors(TgBot::Bot* bot, int64_t chatId, int errors);

    static void emptyQuestionsList(TgBot::Bot* bot, int64_t chatId);

    static void pharasesSuccess(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyBoard);

    static void showQuestions(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardButton::Ptr keyboard);
};

#endif