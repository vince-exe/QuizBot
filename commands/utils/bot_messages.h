#ifndef BOT_MESSAGES_H
#define BOT_MESSAGES_H

#include <tgbot/tgbot.h>

#include "../../game/question.h"
#include "../../game/game.h"
#include "../../utils/bot_utils.h"

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

    static void showQuestions(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    /* Game Messages */

    static TgBot::Message::Ptr secondsLeftMessage(TgBot::Bot* bot, int64_t chatId, int secondsLeft);

    static void editSecondsLeftMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId, int secondsLeft);

    static TgBot::Message::Ptr timeFinishedEditMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId);

    static TgBot::Message::Ptr displayQuestion(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static TgBot::Message::Ptr editDisplayQuestion(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard);

    static void editGameFinished(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard);
};

#endif